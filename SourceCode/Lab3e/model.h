// Dr Paul Robertson.
// Modified and used by Jason Mottershead, Student Number 1300455.

// Model class header file.
// This class allows for model loading, as long as the models are drawn using in triangles.

// Header guard.
#ifndef _MODEL_H_
#define _MODEL_H_

// Include files here.
#include <Windows.h>
#include <fstream>
#include <gl/gl.h>
#include <gl/glu.h>
#include <vector>
#include "token_stream.h"
#include "vec3.h"
#include "SOIL.h"

using namespace std;

class Model
{
	public:
		// Methods.
		bool Load(char*, char*);
		void Render();
	
	private:
		// Attributes.
		int m_vertexCount;
		GLuint texture;

		// vectors for storing model data, for your use
		vector<float> vertex, normals, texCoords;

		// Methods.
		void LoadTexture(char*);
		bool LoadModel(char*);		
};

#endif