# Прошивка NodeMcu для мониторинга и управления температурой

Прошивка написана для контроллера **NodeMcu** (ESP8266) в среде разработки **Arduino IDE**.
Данные отправляются на сервер Blynk, из приложения Blynk можно отслеживать показания
и менять максимальную температуру включения кулера.

На текущий момент прошивка позволяет снимать показания с настраеваемого количества термодатчиков **ds18b20**.
Максимальный лимит датчиков на один канал **D2** контроллера - 6 датчиков.

## Настройка интеграции с Blynk
После регистрации на сервисе [Blynk](https://blynk.io/) и добавления приложения необходимо ввести полученный токен вместо временной фразы *YOUR_BLYNK_TOKEN*
Так же необходимо вписать данные WiFi-сети в 2 следующие строки.
После подключения в приложении Blynk можно добавить любые виджеты и настроить их на виртуальные пины.
Подробные описания подключения к Blynk легко можно найти как в текстовом виде, так и на Youtube.

[Пример настройки приложения после интеграции](https://techmeat.net/images/growbox2.gif)

![GrowBox in Blink](https://techmeat.net/images/growbox2.gif)

Примечания:
- Бесплатный аккаунт Blynk позволяет добавить небольшое количество виджетов на экран проекта, в моем примере лимит исчерпан полностью, дальнейшее увеличение виджетов платное. 
- График в Blynk ограничен 4 показаниями.
