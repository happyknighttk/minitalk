# Minitalk

In this 42 Istanbul project, I wrote a small data exchange program using UNIX signals.

Minitalk is a simple client-server communication program that allows you to send text messages from a client to a server using signals. The client sends individual bits of data as signals to the server, and the server reconstructs the message from these signals.

The server will display its process ID (PID) upon startup.

### Client

Run the client with the server's PID and the message you want to send as arguments: 
./client [server_pid] [message]

- `[server_pid]`: The process ID of the server, as displayed when the server starts.
- `[message]`: The text message you want to send to the server.

Example:

./client 12345 "Hello, Minitalk!"

## How It Works

- The client sends individual bits of the message to the server by using signals (`SIGUSR1` and `SIGUSR2`) to represent `1` and `0`, respectively.
- The server listens for these signals and reconstructs the message as it receives the bits.
- The communication is completed when the client sends a newline character and a null terminator to indicate the end of the message.

---

Bu 42 İstanbul projesinde UNIX sinyallerini kullanarak küçük bir veri değişim programı yazdım.

# Minitalk

Minitalk, istemci ve sunucu arasında sinyalleri kullanarak metin iletilmesini sağlayan basit bir istemci-sunucu iletişim programıdır. İstemci, veriyi sunucuya sinyaller olarak gönderir ve sunucu bu sinyallerden mesajı yeniden oluşturur.

Sunucu başlatıldığında işlem kimliği (PID) görüntülenir.

### İstemci

İstemciyi sunucunun PID'si ve göndermek istediğiniz mesajı argümanlar olarak kullanarak çalıştırın:
./client [server_pid] [mesaj]

- `[server_pid]`: Sunucunun başladığında görünen işlem kimliği (PID).
- `[mesaj]`: Sunucuya göndermek istediğiniz metin mesajı.

Örnek:

./client 12345 "Merhaba, Minitalk!"

## Nasıl Çalışır

- İstemci, 1 ve 0'ları temsil etmek için sinyaller (SIGUSR1 ve SIGUSR2) kullanarak mesajın her bir bitini sunucuya gönderir.
- Sunucu bu sinyalleri dinler ve sinyalleri aldıkça mesajı yeniden oluşturur.
- İletişim, istemcinin bir satır sonu karakteri ve null terminator göndererek tamamlanır, bu da iletişimin sonunu belirtir.

