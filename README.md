# EMICIDA — placa de arte com 6 LEDs

Placa de arte em homenagem ao rapper Emicida, desenhada na serigrafia, com **6 LEDs** de 5 mm (4 vermelhos e 2 azuis) ligados a uma **barra de 7 pinos 90°** na borda da placa. Acompanha o firmware com 20 sequências de pisca-pisca.

<p align="center">
  <img src="imagem_1.png" width="45%">
  <img src="imagem_2.png" width="45%">
</p>

## Funcionalidades

- ✅ **Barra de pinos 1×07 90°** (J1) na borda — 1 GND + 6 canais
- ✅ **6 LEDs 5 mm** THT (D1–D6): D1 vermelho, D2 vermelho, D3 vermelho, D4 vermelho, D5 azul, D6 azul
- ✅ **6 resistores 220 Ω 1/4 W** axiais (R1–R6), um por LED
- ✅ Liga em qualquer microcontrolador (Arduino, ESP32, Pico) com GND comum
- ✅ **Arte na serigrafia** recortada em volta de cada LED (nada de tinta sobre pad)
- ✅ Placa **100 × 100 mm**, 2 camadas, plano de GND nas duas faces

## Ligação dos LEDs

| LED | Cor | Resistor | Pino J1 / sinal | Corrente @ 5 V |
|---|---|---|---|---|
| D1 | vermelho | R1 220 Ω | J1.2 · LED1 | ≈ 13,6 mA |
| D2 | vermelho | R2 220 Ω | J1.3 · LED2 | ≈ 13,6 mA |
| D3 | vermelho | R3 220 Ω | J1.4 · LED3 | ≈ 13,6 mA |
| D4 | vermelho | R4 220 Ω | J1.5 · LED4 | ≈ 13,6 mA |
| D5 | azul | R5 220 Ω | J1.6 · LED5 | ≈ 9,1 mA |
| D6 | azul | R6 220 Ω | J1.7 · LED6 | ≈ 9,1 mA |

Cada canal: **pino → 220 Ω → LED → GND** (nível alto acende). Todos acesos ≈ **73 mA**.

| J1 | Sinal |
|---|---|
| 1 | GND |
| 2 | LED1 (D1) |
| 3 | LED2 (D2) |
| 4 | LED3 (D3) |
| 5 | LED4 (D4) |
| 6 | LED5 (D5) |
| 7 | LED6 (D6) |

> Em 3,3 V (ESP32 / Pico) os LEDs vermelho/amarelo ficam com ≈ 6 mA e o azul fica bem fraco (≈ 1 mA).

## Diagrama de blocos

```
┌──────────────────────┐   LED1 … LED6      ┌──────────────────────────┐
│  J1 barra 1×07 90°   │ ─────────────────► │ 6 × [220 Ω → LED 5 mm]   │
│  1 GND · 2–7 canais  │ ◄──────── GND ──── │  R1–R6       D1–D6       │
└──────────────────────┘                    └──────────────────────────┘
```

## Firmware

`firmware/EMICIDA/EMICIDA.ino` — 20 sequências de pisca-pisca (vai-e-volta, ping-pong, ondas, contagem binária, alarme…).

Ligação usada no firmware: **Arduino D8 … D13 → J1 pinos 2 … 7** (LED1 … LED6) e **GND → J1 pino 1**.

Vídeo e foto da placa montada em `docs/`.

## Esquemático (KiCad 10)

| Pág. | Folha | Conteúdo |
|---|---|---|
| 1 | Capa (A2) | blocos, mapa dos LEDs na placa, vista 3D |
| 2 | LEDS | D1–D6 + R1–R6 |
| 3 | CONN | J1 (barra 1×07 90°) + PWR_FLAG do GND |

## Lista de materiais

| Ref. | Qtd | Valor | Footprint |
|---|---|---|---|
| D1,D2,D3,D4 | 4 | LED 5 mm vermelho | ZAT_LED:LED_D5.0mm_Red |
| D5,D6 | 2 | LED 5 mm azul | ZAT_LED:LED_D5.0mm_Blue |
| J1 | 1 | Barra de pinos 1×07 90° | ZAT_Connector:PinHeader_1x07_P2.54mm_RightAngle_EdgeMount |
| R1–R6 | 6 | 220 Ω 1/4 W | ZAT_Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal_220R |

## Arquivos

- `EMICIDA.kicad_pro` — projeto KiCad 10 (bibliotecas globais KiCad + ZAT, sem pasta lib)
- `Zat_TitleBlock.kicad_wks` — moldura Zat Electronic
- `packages3D/` — modelos 3D usados na vista 3D

## Licença / autor

Projeto **Zat Electronic** — Kenneth Zat · Osasco/SP · hardware aberto.

*Revisão R01 — 2026-11-12 — KiCad 10.*
