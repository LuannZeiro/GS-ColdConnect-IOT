# 🌡️ ColdConnect - Solução IoT Integrada
# 👥 Integrantes: Henzo Puchetti - RM555179 / Luann Mariano - RM558548
📑 Descrição
Este projeto foi desenvolvido como parte do desafio da disciplina Disruptive Architectures: IoT, IoB & Generative IA. A proposta consiste em integrar sensores e atuadores com um sistema IoT para coleta, processamento e exibição de dados em tempo real, utilizando protocolos e plataformas adequadas.

⚙️ Tecnologias Utilizadas
ESP32 — Microcontrolador para coleta de dados.

Sensor DHT22 — Para medição de temperatura e umidade.

Atuador LED — Acionado automaticamente conforme condição de temperatura.

Protocolo MQTT — Comunicação entre ESP32 e Node-RED.

Broker HiveMQ — Broker MQTT público.

Node-RED — Gateway e dashboard para visualização dos dados.

Dashboard Node-RED — Monitoramento visual dos dados.

🖥️ Funcionalidades
✅ Coleta de temperatura e umidade pelo sensor DHT22.
✅ Envio dos dados em formato JSON para o broker MQTT.
✅ Acionamento de um LED no pino 5 quando a temperatura for menor ou igual a -16°C.
✅ Criação de um fluxo no Node-RED para receber, processar e exibir os dados em tempo real.
✅ Dashboard visual com gráficos e indicadores.

📡 Descrição do Funcionamento
O ESP32 coleta a temperatura e umidade a cada 5 segundos.

Os dados são enviados via MQTT no tópico:
coldconnect/sensores

No Node-RED, um fluxo consome esses dados e os exibe no dashboard.

O LED é acionado automaticamente como um sistema de alerta para temperaturas extremamente baixas.

📝 Estrutura do Projeto
bash
Copiar
Editar
/coldconnect
├── codigo-esp32.ino
├── fluxo-node-red.json
├── imagens/
│   ├── dashboard.png
│   ├── fluxo.png
├── README.md
🚀 Como Executar
1. Configurar o ESP32
Faça upload do código para o ESP32.

Ajuste a rede Wi-Fi e o tópico MQTT, se necessário.

2. Configurar o Node-RED
Importe o arquivo fluxo-node-red.json no Node-RED.

Configure o nó MQTT para se conectar ao broker.hivemq.com e ao tópico coldconnect/sensores.

3. Executar
Visualize os dados em tempo real no dashboard.

Teste a condição de acionamento do LED.


🏆 Requisitos Atendidos
✅ Sistema IoT com sensor e atuador.
✅ Hardware: ESP32 com sensor DHT22 e LED.
✅ Dashboard para monitoramento em tempo real.
✅ Gateway utilizando Node-RED com protocolo MQTT e JSON.
✅ Protótipo funcional, testado e validado.

👥 Integrantes
