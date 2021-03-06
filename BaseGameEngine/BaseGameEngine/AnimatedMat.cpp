#include "AnimatedMat.h"



AnimatedMat::AnimatedMat()
{
	shader = Shader::GetShader("Shaders/animVex.vex", "Shaders/animFreg.freg");
}

AnimatedMat::AnimatedMat(aiMaterial * material, string directory) : AnimatedMat()
{
}

void AnimatedMat::Bind(mat4 view, mat4 model)
{
	shader->Use();
	bindViewAndModelMatrix(view, model);
}

vector<Texture*> AnimatedMat::GetAllTextures()
{
	return vector<Texture*>();
}

