# **Projeto Final de Internet das Coisas: Internet of Medical Things**

Projeto desenvolvido por **Bruno Lobo (a54916)** e **André Oliveira (44613)**, alunos do curso de **Engenharia Informática** do **IPB - ESTiG**, no ano letivo **2024/2025**.

---

## 🩺 Descrição

A pandemia de COVID-19 acelerou a necessidade da adoção de tecnologias emergentes no setor da saúde, especialmente soluções baseadas em **Internet das Coisas (IoT)**. Estas tecnologias visam melhorar a conectividade e a troca de informações em tempo real entre pacientes, profissionais de saúde e instituições hospitalares.

---

## 🎯 Objetivo

Desenvolver um sistema de monitorização remota de pacientes, utilizando tecnologias de **Internet das Coisas (IoT)**, para recolher, processar e transmitir dados médicos de forma segura e eficiente.

---

## 🛠️ Tecnologias Utilizadas

- Simulador online **Wokwi** (ESP32)
- **Node-RED**
- **InfluxDB**
- Protocolo **MQTT**
- Algoritmo de encriptação **AES**

---

## 💡 Solução Apresentada

Sensores **DHT22** foram conectados a um **ESP32** para medir a temperatura de até quatro pacientes. As leituras são recolhidas e enviadas via **MQTT** em formato **JSON** para um tópico subscrito no **Node-RED**. Os dados são enriquecidos com informações simuladas — como ritmo cardíaco, pressão arterial e oximetria — e estruturados em objetos de paciente.

Estes objetos são organizados num **array** que é:

- Enviado para o **InfluxDB** para armazenamento e análise;
- Encriptado com **AES** e enviado por **MQTT** para os dashboards da aplicação do **Paciente** e do **Hospital**.

---

## 📁 Organização do Repositório

- `ProjetoFinal(node-red).json`: Fluxo do Node-RED com lógica de receção, enriquecimento e envio dos dados.
- `README.md`: Documento atual com as informações e estrutura do projeto.
- `ProjFinalIoT.ino`: Código-fonte do ESP32 responsável pela recolha dos dados dos sensores.
- `Wokwi_Link.txt`: Link de acesso à simulação do projeto na plataforma Wokwi.
- `diagram.json`: Diagrama visual da montagem do circuito na simulação Wokwi.
- `libraries.txt`: Lista das bibliotecas utilizadas no projeto.
- `video_demonstrativo.txt` *(a adicionar)*: Link privado para a demonstração em vídeo do funcionamento do sistema.

---
