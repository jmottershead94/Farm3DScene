// Jason Mottershead, Student Number 1300455.

// Room class header file.
// In this class is where the room will be first created.
// A basic cubic room for a template.

// Texture references:
//	Common:
//		Most of my common/standard textures (fabrics, materials, paintings, wood etc.) are from here - http://www.mayang.com/textures/
//	Ladder:
//		Ladder texture - http://2i.c-b.co/is/image/CB2/WhiteLadderF14/&$web_zoom$&/1406051420/white-ladder.jpg
//	Posters:
//		Batman vs Superman -  http://www.comicbookmovie.com/fansites/BakiKaya/news/?a=107092
//		Breaking Bad - http://www.amazon.co.uk/Breaking-Bad-Knocks-Maxi-Poster/dp/B00ED2BFW8
//		The Walking Dead - http://www.ebay.co.uk/bhp/the-walking-dead-poster

// Header guard.
#ifndef _ROOM_H_
#define _ROOM_H_

// Include files here.
#include "shape.h"
#include "model.h"
#include "camera.h"

// Room IS A shape, therefore it inherits from the shape.
class Room : public Shape
{
	public:
		// Attributes.
		GLuint bed_covers_, bed_sheets_, fabric_crosshatch_, fabric_light_, fabric_lightswirls_, fabric_rough_carpet_, floor_dark_diamonds_, floor_dark_tiles_,
			marble_, matress_cover_, metal_scratched_, painting_brightfields_, painting_darkfields_, painting_farm_, painting_house_, painting_river_, painting_trees_, pillow_,
			poster_batman_v_superman_, poster_breaking_bad_, poster_the_walking_dead_, red_, white_, wood_, wood_light_, wooden_board_;
		
		// Methods.
		Room();
		~Room();
		void Init();
		virtual void Render(Vec3& position, Vec2& dimension, Vec2& texture_coordinate, Vec2& texture_dimension, int recursions, bool reflective, bool has_front_door, bool has_leftside_door, bool has_back_door, bool has_rightside_door, bool has_front_window, bool has_left_window, bool has_back_window, bool has_right_window, bool has_upstairs_access, bool has_downstairs_access);

	protected:
		// Here are functions for objects that will only appear in rooms.
		// These are more general objects and not really specific to the room.
		// Passing in textures can make them seem different and unique to the room.

		// Chairs will be used in a couple of rooms around the house.
		void CreateChair(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension);

		// Couches will be used only in the living room.
		void CreateCouch(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension);

		// The tables will be used in most of the rooms.
		void CreateTable(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension);

		// This function has an added parameter for checking to see if the bed is a double bed or not.
		// This will help make different kinds of beds in the house.
		// This will be used in both the normal bedroom, and the master bedroom.
		void CreateBed(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, bool is_double);

		// This will be used only in the bath room.
		void CreateBathTub(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension);

		// Drawers will be used in most of the rooms.
		void CreateDrawers(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension);

		// The work top will only be used in the kitchen.
		void CreateWorkTop(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension);

		// Cupboards will be used in the kitchen.
		void CreateCupboard(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension);

		// This will be used in most rooms.
		void CreateLamp(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension);

		// This will be used in most rooms. 
		void CreateLightShade(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension);

		// This will be used in most rooms.
		// This will show off the use of vertex arrays for drawing the quads.
		void CreatePainting(Vec3 position, Vec2 dimension, Vec2 texture_coordinate, Vec2 texture_dimension, const char* painting_name);
};

#endif