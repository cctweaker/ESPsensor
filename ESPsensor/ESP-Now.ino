void init_espnow()
{
    if (esp_now_init() != 0)
        goto_sleep();

    esp_now_set_kok(kok, 16);

    esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

    esp_now_add_peer(gmac, ESP_NOW_ROLE_COMBO, WIFI_CHANNEL, key, 16);
    esp_now_set_peer_key(gmac, key, 16);

    esp_now_register_send_cb(txcb);
    esp_now_register_recv_cb(rxcb);
}

void send_data()
{
    uint8_t byteArray[sizeof(tx)];
    memcpy(byteArray, &tx, sizeof(tx));
    esp_now_send(gmac, byteArray, sizeof(tx));

    SENT = true;
}

void txcb(uint8_t *mac, uint8_t sendStatus)
{
    if (sendStatus == 0)
        ACK = true;
}

void rxcb(uint8_t *senderMac, uint8_t *incomingData, uint8_t len) {}