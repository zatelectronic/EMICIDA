// Definição dos pinos onde os LEDs estão conectados (8 a 13)
const int LED_PINS[] = {8, 9, 10, 11, 12, 13};
const int NUM_LEDS = 6; 

// Constantes para controle de tempo (em milissegundos)
const int DELAY_EXTREMO = 50; // Para flashes muito rápidos
const int DELAY_RAPIDO = 100;
const int DELAY_MEDIO = 180;
const int DELAY_LENTO = 300; 
const int DELAY_PAUSA = 700; // Pausa longa entre as sequências

void setup() {
  // Configura todos os pinos dos LEDs como OUTPUT
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW); // Garante que estão todos apagados
  }
  // Inicializa o gerador de números aleatórios
  randomSeed(analogRead(A0));
}

// ---------------------------------------------
// --- 10 Funções de Sequência de Pisca-Pisca (Originais) ---
// ---------------------------------------------

// 1. Vai e Volta (Efeito de Carro de Corrida)
void sequenciaVaiEVolta(int tempo) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(tempo);
  }
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    digitalWrite(LED_PINS[i], LOW);
    delay(tempo);
  }
}

// 2. Alternada (Pares e Ímpares)
void sequenciaAlternada(int tempo) {
  for (int i = 0; i < NUM_LEDS; i += 2) {
    digitalWrite(LED_PINS[i], HIGH);
  }
  delay(tempo);
  for (int i = 0; i < NUM_LEDS; i += 2) {
    digitalWrite(LED_PINS[i], LOW);
  }
  for (int i = 1; i < NUM_LEDS; i += 2) {
    digitalWrite(LED_PINS[i], HIGH);
  }
  delay(tempo);
  for (int i = 1; i < NUM_LEDS; i += 2) {
    digitalWrite(LED_PINS[i], LOW);
  }
}

// 3. Concentração (Centro para as Pontas e Volta)
void sequenciaConcentracao(int tempo) {
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    digitalWrite(LED_PINS[NUM_LEDS / 2 - 1 - i], HIGH); 
    digitalWrite(LED_PINS[NUM_LEDS / 2 + i], HIGH);      
    delay(tempo);
    digitalWrite(LED_PINS[NUM_LEDS / 2 - 1 - i], LOW);
    digitalWrite(LED_PINS[NUM_LEDS / 2 + i], LOW);
  }
}

// 4. Flash (Todos Juntos)
void sequenciaFlash(int repeticoes, int tempo) {
  for (int r = 0; r < repeticoes; r++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(LED_PINS[i], HIGH);
    }
    delay(tempo);
    for (int i = 0; i < NUM_LEDS; i++) {
      digitalWrite(LED_PINS[i], LOW);
    }
    delay(tempo);
  }
}

// 5. Deslizar (Preenchimento e Limpeza na mesma direção)
void sequenciaDeslizar(int tempo) {
  // Acende do 8 ao 13, mantendo acesos
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(tempo);
  }
  delay(DELAY_MEDIO); // Mantém aceso por um tempo
  // Apaga do 8 ao 13
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
    delay(tempo);
  }
}

// 6. Aleatória (Pisca um LED por vez em posições não ordenadas)
void sequenciaAleatoria(int ciclos, int tempo) {
  for (int c = 0; c < ciclos; c++) {
    int pino_aleatorio = random(0, NUM_LEDS); 
    digitalWrite(LED_PINS[pino_aleatorio], HIGH);
    delay(tempo);
    digitalWrite(LED_PINS[pino_aleatorio], LOW);
    delay(tempo / 2);
  }
}

// 7. Sequência Ping-Pong (Pontas para o centro e volta - Acende e Apaga no passo)
void sequenciaPingPong(int tempo) {
  // Pontas para o centro (Acende & Apaga)
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    digitalWrite(LED_PINS[NUM_LEDS - 1 - i], HIGH);
    delay(tempo);
    digitalWrite(LED_PINS[i], LOW);
    digitalWrite(LED_PINS[NUM_LEDS - 1 - i], LOW);
    delay(tempo / 2);
  }
  // Centro para as pontas (Acende & Apaga)
  for (int i = NUM_LEDS / 2 - 1; i >= 0; i--) {
    digitalWrite(LED_PINS[i], HIGH);
    digitalWrite(LED_PINS[NUM_LEDS - 1 - i], HIGH);
    delay(tempo);
    digitalWrite(LED_PINS[i], LOW);
    digitalWrite(LED_PINS[NUM_LEDS - 1 - i], LOW);
    delay(tempo / 2);
  }
}

// 8. Aleatória com Rastro (Acumula LEDs acesos e limpa)
void sequenciaAleatoriaRastro(int passos, int tempo) {
  // Acende LEDs aleatórios, mantendo-os acesos
  for (int p = 0; p < passos; p++) {
    int pino_aleatorio = random(0, NUM_LEDS); 
    digitalWrite(LED_PINS[pino_aleatorio], HIGH);
    delay(tempo);
  }
  
  // Apaga todos de uma vez
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }
  delay(tempo * 2); 
}

// 9. Sequência Dupla (Pisca em Pares: 8&9, 10&11, 12&13)
void sequenciaDupla(int tempo) {
  for (int i = 0; i < NUM_LEDS; i += 2) {
    // Acende o par
    digitalWrite(LED_PINS[i], HIGH);
    digitalWrite(LED_PINS[i + 1], HIGH);
    delay(tempo);
    
    // Apaga o par
    digitalWrite(LED_PINS[i], LOW);
    digitalWrite(LED_PINS[i + 1], LOW);
    delay(tempo / 2);
  }
}

// 10. Sequência Metades Alternadas (1ª Metade pisca, depois a 2ª)
void sequenciaMetades(int tempo) {
  // Acende e apaga a primeira metade (8, 9, 10)
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    digitalWrite(LED_PINS[i], HIGH);
  }
  delay(tempo);
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }
  delay(tempo / 2);
  
  // Acende e apaga a segunda metade (11, 12, 13)
  for (int i = NUM_LEDS / 2; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
  }
  delay(tempo);
  for (int i = NUM_LEDS / 2; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }
  delay(tempo / 2);
}

// ---------------------------------------------
// --- 10 NOVAS Funções de Sequência de Pisca-Pisca ---
// ---------------------------------------------

// 11. Ondas (Acende um por um, apaga todos juntos)
void sequenciaOndas(int tempo) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(tempo);
  }
  delay(tempo * 2); 
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
  }
  delay(tempo); 
}

// 12. Pêndulo (Vai e Volta, Apagando o anterior)
void sequenciaPendulo(int tempo) {
  // Vai
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    if (i > 0) digitalWrite(LED_PINS[i - 1], LOW);
    delay(tempo);
  }
  // Volta
  for (int i = NUM_LEDS - 2; i >= 0; i--) {
    digitalWrite(LED_PINS[i], HIGH);
    digitalWrite(LED_PINS[i + 1], LOW);
    delay(tempo);
  }
  digitalWrite(LED_PINS[0], LOW); // Apaga o último
  delay(tempo / 2);
}

// 13. Piscada Externa/Interna (Alterna entre as pontas e os interiores)
void sequenciaExternaInterna(int tempo) {
  // Externa (8 & 13)
  digitalWrite(LED_PINS[0], HIGH);
  digitalWrite(LED_PINS[NUM_LEDS - 1], HIGH);
  delay(tempo);
  digitalWrite(LED_PINS[0], LOW);
  digitalWrite(LED_PINS[NUM_LEDS - 1], LOW);
  delay(tempo / 2);

  // Interior (9 & 12)
  digitalWrite(LED_PINS[1], HIGH);
  digitalWrite(LED_PINS[NUM_LEDS - 2], HIGH);
  delay(tempo);
  digitalWrite(LED_PINS[1], LOW);
  digitalWrite(LED_PINS[NUM_LEDS - 2], LOW);
  delay(tempo / 2);
  
  // Centro (10 & 11)
  digitalWrite(LED_PINS[2], HIGH);
  digitalWrite(LED_PINS[NUM_LEDS - 3], HIGH);
  delay(tempo);
  digitalWrite(LED_PINS[2], LOW);
  digitalWrite(LED_PINS[NUM_LEDS - 3], LOW);
  delay(tempo / 2);
}

// 14. Corrida Reversa (Vai e Volta, mas apagando ao invés de acender)
void sequenciaCorridaReversa(int tempo) {
  // Primeiro, acende todos
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
  }
  delay(tempo * 2);
  
  // Apaga do 8 ao 13
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], LOW);
    delay(tempo);
  }
  // Acende do 13 ao 8
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(tempo);
  }
  delay(tempo);
}

// 15. Acende um a um, apaga um a um na ordem oposta
void sequenciaPreencherInverter(int tempo) {
  // Preenche (8 -> 13)
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    delay(tempo);
  }
  delay(tempo * 2);

  // Apaga (13 -> 8)
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    digitalWrite(LED_PINS[i], LOW);
    delay(tempo);
  }
}

// 16. Flash Duplo Alternado (Pares piscam 2x, depois Ímpares 2x)
void sequenciaFlashAlternadoDuplo(int tempo) {
  // Pares 2x
  for(int r = 0; r < 2; r++) {
    for (int i = 0; i < NUM_LEDS; i += 2) {
      digitalWrite(LED_PINS[i], HIGH);
    }
    delay(tempo);
    for (int i = 0; i < NUM_LEDS; i += 2) {
      digitalWrite(LED_PINS[i], LOW);
    }
    delay(tempo);
  }
  
  // Ímpares 2x
  for(int r = 0; r < 2; r++) {
    for (int i = 1; i < NUM_LEDS; i += 2) {
      digitalWrite(LED_PINS[i], HIGH);
    }
    delay(tempo);
    for (int i = 1; i < NUM_LEDS; i += 2) {
      digitalWrite(LED_PINS[i], LOW);
    }
    delay(tempo);
  }
}

// 17. Duplo Vai e Volta (Dois LEDs acesos "correndo" juntos)
void sequenciaDuploCorrida(int tempo) {
  // Vai (8&9, 9&10, ..., 12&13)
  for (int i = 0; i < NUM_LEDS - 1; i++) {
    digitalWrite(LED_PINS[i], HIGH);
    digitalWrite(LED_PINS[i + 1], HIGH);
    if (i > 0) digitalWrite(LED_PINS[i - 1], LOW); // Apaga o anterior
    delay(tempo);
  }
  
  // Volta (13&12, 12&11, ..., 9&8)
  for (int i = NUM_LEDS - 2; i >= 0; i--) {
    digitalWrite(LED_PINS[i], HIGH);
    digitalWrite(LED_PINS[i + 1], HIGH);
    if (i < NUM_LEDS - 2) digitalWrite(LED_PINS[i + 2], LOW); // Apaga o anterior
    delay(tempo);
  }
  // Apaga os dois últimos (8 e 9)
  digitalWrite(LED_PINS[0], LOW);
  digitalWrite(LED_PINS[1], LOW);
  delay(tempo / 2);
}

// 18. Contagem Binária (Demonstração visual de 0 a 63 - requer 6 LEDs)
// OBS: 6 LEDs dão $2^6 = 64$ estados, de 0 a 63.
void sequenciaContagemBinaria(int tempo) {
  for (int j = 0; j < 64; j++) { // 64 estados (0 a 63)
    for (int i = 0; i < NUM_LEDS; i++) {
      // Verifica o bit na posição 'i'
      if ((j >> i) & 1) { 
        digitalWrite(LED_PINS[i], HIGH);
      } else {
        digitalWrite(LED_PINS[i], LOW);
      }
    }
    delay(tempo);
  }
}

// 19. Piscada Aleatória em Grupo (3 LEDs aleatórios piscam juntos)
void sequenciaGrupoAleatorio(int ciclos, int tempo) {
  for (int c = 0; c < ciclos; c++) {
    int pinos_acesos[3];
    
    // Seleciona 3 pinos únicos aleatoriamente
    for(int i = 0; i < 3; i++) {
      int novo_pino;
      bool repetido;
      do {
        novo_pino = random(0, NUM_LEDS);
        repetido = false;
        for(int j = 0; j < i; j++) {
          if (pinos_acesos[j] == novo_pino) {
            repetido = true;
            break;
          }
        }
      } while (repetido);
      pinos_acesos[i] = novo_pino;
      digitalWrite(LED_PINS[novo_pino], HIGH);
    }
    
    delay(tempo);
    
    // Apaga os 3 pinos
    for(int i = 0; i < 3; i++) {
      digitalWrite(LED_PINS[pinos_acesos[i]], LOW);
    }
    delay(tempo / 2);
  }
}

// 20. Sequência de Alarme (Flash rápido externo, depois Flash lento geral)
void sequenciaAlarme(int tempo) {
  // Flash externo rápido (8 e 13)
  for (int r = 0; r < 4; r++) {
    digitalWrite(LED_PINS[0], HIGH);
    digitalWrite(LED_PINS[NUM_LEDS - 1], HIGH);
    delay(tempo / 2);
    digitalWrite(LED_PINS[0], LOW);
    digitalWrite(LED_PINS[NUM_LEDS - 1], LOW);
    delay(tempo / 2);
  }
  
  // Flash geral lento
  sequenciaFlash(2, tempo * 3);
}

// ---------------------------------------------
// --- Loop Principal (Orquestrando as 20 Sequências) ---
// ---------------------------------------------

void loop() {
  // --- ORIGINAIS (1 a 10) ---

  // 1. Vai e Volta 
  sequenciaVaiEVolta(DELAY_RAPIDO);
  sequenciaVaiEVolta(DELAY_RAPIDO / 2);
  delay(DELAY_PAUSA); 

  // 2. Alternada (Pares/Ímpares)
  for(int i = 0; i < 4; i++) {
    sequenciaAlternada(DELAY_MEDIO);
  }
  delay(DELAY_PAUSA); 

  // 3. Aleatória (Pisca um por vez)
  sequenciaAleatoria(12, DELAY_EXTREMO); 
  delay(DELAY_PAUSA);

  // 4. Deslizar (Preenchimento)
  sequenciaDeslizar(DELAY_MEDIO);
  delay(DELAY_PAUSA);
  
  // 5. Dupla (Pisca em Pares)
  for (int i = 0; i < 3; i++) {
    sequenciaDupla(DELAY_RAPIDO);
  }
  delay(DELAY_PAUSA);

  // 6. Concentração (Centro para as Pontas e Volta)
  for(int i = 0; i < 3; i++) {
    sequenciaConcentracao(DELAY_LENTO);
  }
  delay(DELAY_PAUSA);

  // 7. Metades Alternadas 
  for (int i = 0; i < 4; i++) {
    sequenciaMetades(DELAY_MEDIO);
  }
  delay(DELAY_PAUSA);
  
  // 8. Ping-Pong (Pontas para o centro e volta - Acende/Apaga)
  for (int i = 0; i < 3; i++) {
    sequenciaPingPong(DELAY_RAPIDO);
  }
  delay(DELAY_PAUSA);
  
  // 9. Aleatória com Rastro 
  sequenciaAleatoriaRastro(10, DELAY_MEDIO); 
  delay(DELAY_PAUSA);

  // 10. Flash (Todos Juntos)
  sequenciaFlash(8, DELAY_EXTREMO); 
  delay(DELAY_PAUSA * 2); 
  
  // -------------------------
  // --- NOVOS EFEITOS (11 a 20) ---
  // -------------------------

  // 11. Ondas (Acende 1 a 1, apaga todos juntos)
  sequenciaOndas(DELAY_MEDIO);
  sequenciaOndas(DELAY_RAPIDO);
  delay(DELAY_PAUSA);
  
  // 12. Pêndulo (Vai e Volta, Apagando o anterior)
  for(int i = 0; i < 2; i++) {
    sequenciaPendulo(DELAY_MEDIO);
  }
  delay(DELAY_PAUSA);

  // 13. Piscada Externa/Interna (Alterna em Pares Simétricos)
  for(int i = 0; i < 3; i++) {
    sequenciaExternaInterna(DELAY_RAPIDO);
  }
  delay(DELAY_PAUSA);

  // 14. Corrida Reversa (Apaga 1 a 1, acende 1 a 1)
  sequenciaCorridaReversa(DELAY_MEDIO);
  delay(DELAY_PAUSA);

  // 15. Preencher e Inverter (Preenche 8->13, Apaga 13->8)
  sequenciaPreencherInverter(DELAY_RAPIDO);
  delay(DELAY_PAUSA);

  // 16. Flash Duplo Alternado (Pares 2x, Ímpares 2x)
  sequenciaFlashAlternadoDuplo(DELAY_MEDIO);
  delay(DELAY_PAUSA);

  // 17. Duplo Vai e Volta (Dois LEDs correndo juntos)
  for(int i = 0; i < 2; i++) {
    sequenciaDuploCorrida(DELAY_MEDIO);
  }
  delay(DELAY_PAUSA);

  // 18. Contagem Binária
  sequenciaContagemBinaria(DELAY_RAPIDO); 
  delay(DELAY_PAUSA);

  // 19. Grupo Aleatório (3 LEDs juntos)
  sequenciaGrupoAleatorio(8, DELAY_MEDIO);
  delay(DELAY_PAUSA);

  // 20. Alarme (Flash externo rápido, Flash geral lento)
  sequenciaAlarme(DELAY_RAPIDO);
  delay(DELAY_PAUSA * 3); // Pausa bem longa para o final do super-ciclo
}