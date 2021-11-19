# arduino-monitoramento-rios
Projeto exemplo para a coleta de dados com sensores arduino para o monitoramento em tempo real de água, incluso node-red que envia estes dados para um banco local e um dashboard capaz de acompanhar os valores e enviar um aviso para o próprio dispositivo ou redes sociais caso seja necessário.

SimulIDE estava na versão 0.4.15 quando foi realizado esse exemplo.

Integrantes:
- João Henrique dos Santos da Silva
- João Vitor Camargo
- Murilo Bapdista

Necessário para o uso do exemplo:
Bibliotecas do Arduino: ArduinoJson
Bibliotecas Node-RED: node-red-node-twitter, node-red-node-sqlite, node-red-node-serialport, dashboard-evi e sqlite-plugin-red

Vídeo de demonstração: https://www.youtube.com/watch?v=aO_q5XIeUEg

Instruções:
- Baixe SIMULIDE e instale corretamente, instale Node-RED e instale a aplicação do arduino.
- Instale as bibliotecas necessárias de cada um.
- Importe o arquivo .ino e .simu no SimulIDE.
- Inclua o código no arduino.
- Faça as configurações necessárias do NODE e import o arquivo JSON do projeto. 
- Abra o dashboard no node-red.
- Programe o banco SQLite local com base no exemplo.
- Ligue o arduino.
- Verique se está tudo funcionando corretamente, se os dados são armazenados no banco, se o Twitter mostrado no vídeo esta recebendo os dados conforme apertar o botão e se o dashboard esta demonstrando em tempo real os valores e o botão realmente envie para o Twitter. 
