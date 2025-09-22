/* Test program for parser functionality only */
#include "inc/cub3d.h"

int main(int argc, char **argv)
{
	t_game game;
	
	if (argc != 2)
	{
		printf("Usage: %s <map.cub>\n", argv[0]);
		return (1);
	}
	
	// Initialize game structure
	init_game(&game);
	
	// Test parsing
	printf("Testing parser with file: %s\n", argv[1]);
	
	if (parse_file(argv[1], &game) == -1)
	{
		printf("Error: Failed to parse file\n");
		return (1);
	}
	
	printf("✓ File parsed successfully\n");
	
	if (validate_map(&game) == -1)
	{
		printf("Error: Map validation failed\n");
		return (1);
	}
	
	printf("✓ Map validation passed\n");
	
	if (load_textures(argv[1], &game) == -1)
	{
		printf("Error: Failed to load textures\n");
		return (1);
	}
	
	printf("✓ Textures loaded successfully\n");
	
	// Initialize player
	init_player(&game);
	printf("✓ Player initialized at position (%.1f, %.1f)\n", 
		game.player.x, game.player.y);
	
	printf("✓ All tests passed! Map dimensions: %dx%d\n", 
		game.map_width, game.map_height);
	
	// Clean up
	cleanup_game(&game);
	
	return (0);
}
