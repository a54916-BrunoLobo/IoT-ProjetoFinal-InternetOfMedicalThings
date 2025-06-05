# **Projeto Final de Internet das Coisas: Internet of Medical Things**
Projeto de grupo por Bruno Lobo (a54916) e André Oliveira (44613), alunos do IPB-ESTiG no Curso de Engenharia Informática no Ano Letivo 2024/2025.


## Descrição:
A pandemia de COVID-19 tem acelerado a necessidade da inclusão de tecnologias emergentes no setor de saúde, principalmente tecnologias relacionadas a Internet das Coisas (IdC), visando promover a conectividade e troca de informações em tempo real entre pacientes, profissionais da saúde e hospitais.

## Objetivo:
Desenvolver um sistema que monitore pacientes de forma remota utilizando tecnologias IdC.

### Tecnologias Utilizadas:
Simulador Online de ESP32 (Wokwi), Node-Red, InfluxDB.
### Solução Apresentada:
Utilizamos sensores DHT22 conectados a um ESP32 para medir a temperatura de até quatro pacientes de forma analógica. As leituras são recolhidas e transmitidas via MQTT, em formato JSON, para um tópico ao qual o Node-RED está subscrito. Cada conjunto de dados é associado a um objeto paciente, que inclui também informações simuladas, como ritmo cardíaco, pressão arterial e oximetria. Esses objetos são organizados em um array e enviados simultaneamente para o banco de dados InfluxDB e para os dashboards das aplicações do Paciente e do Hospital. Antes do envio, os dados são encriptados com o algoritmo AES utilizando uma chave secreta.

