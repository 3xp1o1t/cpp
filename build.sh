#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

SOURCE_FILE="${1:-main.cpp}"
OUTPUT_FILE="${SOURCE_FILE%.cpp}.bin"

if [[ ! -f "$SOURCE_FILE" ]]; then
  printf "${RED}❌ Error: El archivo '$SOURCE_FILE' no existe.${NC}\n"
  printf "💡 Usa: $0 <archivo.cpp>\n"
  exit 1
fi

printf "${YELLOW}🔧 Compilando: $SOURCE_FILE → $OUTPUT_FILE${NC}\n"

# Wall, Wextra, Werror = Advertencias y convertir algunas en errores OBLIGA A ESCRIBIR BIEN
# pedantic Cumple extrictamente con el estandar de cpp
# std c++20 usa un cpp mas moderno
# -g para habilidar la depurancion con gdb
# O0 evita la optimizacion para que sea mas facil depurar
g++ -Wall -Wextra -Werror -pedantic -g -O0 --std=c++20 -o "$OUTPUT_FILE" "$SOURCE_FILE"

EXIT_CODE=$?

if [[ $EXIT_CODE -eq 0 ]]; then
  printf "${GREEN}✅ Compilado con éxito!${NC}\n"
  printf "${GREEN}▶️  Ejecuta: ./$OUTPUT_FILE${NC}\n"
else
  printf "${RED}❌ Error de compilación (código: $EXIT_CODE)${NC}\n"
  exit $EXIT_CODE
fi
