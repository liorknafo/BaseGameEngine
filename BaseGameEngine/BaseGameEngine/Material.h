#ifndef __MATERIAL__H
#define __MATERIAL__H

#include <glm\glm.hpp>
#include <assimp\scene.h>
#include <glm/gtc/type_ptr.hpp>
#include <string>

#include "Shader.h"
#include "Texture.h"

#define BIND_TEXTURE(TEX , INDEX) bindTexture(TEX , #TEX , INDEX)

using namespace std;
using namespace glm;

class Material
{
public:
	virtual vector<Texture*> GetAllTextures() = 0;
	virtual void Bind(mat4 view , mat4 model) = 0;

protected:
	Shader* shader;

	//Help to bind the properties
	void bindTexture(Texture* texture, string textureName , GLuint index);
	void bindFloat(GLfloat input, string floatName);
	void bindVector2(vec2 vector2, string vectorName);
	void bindVector3(vec3 vector3, string vectorName);
	void bindVector4(vec4 vector4, string vectoiName);
	void bindMatrix4x4(mat4 matrix, string matrixName);
	void bindViewAndModelMatrix(mat4 view, mat4 model);

	Texture* loadTexture(aiMaterial * material, aiTextureType textureType, string directory);
};
#endif

