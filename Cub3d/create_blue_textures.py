#!/usr/bin/env python3
from PIL import Image
import numpy as np

def create_blue_texture(name, base_color, pattern_type="brick"):
    """Create a blue-toned texture"""
    size = 64
    img = np.zeros((size, size, 3), dtype=np.uint8)
    
    r, g, b = base_color
    
    if pattern_type == "brick":
        # Brick pattern
        for y in range(size):
            for x in range(size):
                # Create brick pattern
                brick_row = y // 8
                brick_offset = (brick_row % 2) * 4
                brick_col = (x + brick_offset) // 8
                
                # Add some variation
                variation = np.random.randint(-20, 20)
                if (x + brick_offset) % 8 == 0 or y % 8 == 0:
                    # Mortar lines - darker
                    img[y, x] = [max(0, r - 40 + variation), 
                                max(0, g - 40 + variation), 
                                max(0, b - 40 + variation)]
                else:
                    # Brick - base color
                    img[y, x] = [min(255, r + variation), 
                                min(255, g + variation), 
                                min(255, b + variation)]
    
    elif pattern_type == "stone":
        # Stone pattern
        for y in range(size):
            for x in range(size):
                # Create stone-like texture with noise
                noise = np.random.randint(-30, 30)
                distance_from_center = ((x - size//2)**2 + (y - size//2)**2)**0.5
                center_effect = int(20 * np.sin(distance_from_center / 5))
                
                img[y, x] = [min(255, max(0, r + noise + center_effect)), 
                            min(255, max(0, g + noise + center_effect)), 
                            min(255, max(0, b + noise + center_effect))]
    
    # Convert to PIL Image and save
    pil_img = Image.fromarray(img)
    pil_img.save(f"textures/{name}.png")
    print(f"Created {name}.png")

# Create blue-toned textures
np.random.seed(42)  # For consistent results

# North wall - Light blue brick
create_blue_texture("north_wall_blue", (100, 150, 200), "brick")

# South wall - Medium blue stone  
create_blue_texture("south_wall_blue", (80, 120, 180), "stone")

# East wall - Dark blue brick
create_blue_texture("east_wall_blue", (60, 100, 160), "brick")

# West wall - Cyan-blue stone
create_blue_texture("west_wall_blue", (70, 140, 190), "stone")

print("Blue textures created successfully!")
