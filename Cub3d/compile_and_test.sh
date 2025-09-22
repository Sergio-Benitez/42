#!/bin/bash

# Script para compilar y probar Cub3D

echo "🔨 Compilando Cub3D..."

# Verificar que existe libft
if [ ! -d "../Libft" ]; then
    echo "❌ Error: No se encuentra la carpeta Libft en el directorio padre"
    echo "💡 Asegúrate de que la estructura sea: 42/Libft/ y 42/Cub3d/"
    exit 1
fi

# Compilar libft primero
echo "📚 Compilando Libft..."
cd ../Libft
make > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "❌ Error compilando Libft"
    exit 1
fi
cd ../Cub3d

# Compilar cub3D
make
if [ $? -ne 0 ]; then
    echo "❌ Error compilando Cub3D"
    exit 1
fi

echo "✅ Compilación exitosa!"

# Verificar que existe el mapa de prueba
if [ ! -f "maps/test.cub" ]; then
    echo "⚠️  No se encuentra el mapa de prueba maps/test.cub"
    exit 1
fi

echo "🎮 Para ejecutar el juego:"
echo "./cub3D maps/test.cub"
echo ""
echo "🎯 Controles:"
echo "  WASD: Movimiento"
echo "  ←→: Rotación"
echo "  ESC: Salir"
