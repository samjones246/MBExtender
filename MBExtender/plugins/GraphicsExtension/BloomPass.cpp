#include "BloomPass.h"
#include "postProcessing.h"

extern FrameBufferObject* gFBO;

BloomPass::BloomPass() : Pass(std::string("bloom"), std::string("platinum/data/shaders/postfxV.glsl"), std::string("platinum/data/shaders/postfxBlurF.glsl"), PassBuffers::Color | PassBuffers::Depth)
{
}

void BloomPass::processPass(Point2I extent) {
	// post processing
	glViewport(0, 0, extent.x, extent.y);
	glPushMatrix();
	glLoadIdentity();

	glPushMatrix();
	glLoadIdentity();

	glBindFramebuffer(GL_FRAMEBUFFER, this->finalFrameBuffer);
	GL_CheckErrors("render bloom");
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// bind shader and texture uniform
	if (!glIsEnabled(GL_TEXTURE_2D))
		glEnable(GL_TEXTURE_2D);

	this->shader->activate();
	this->shader->setUniformLocation("textureSampler", 0);
	this->shader->setUniformLocation("depthSampler", 1);
	this->shader->setUniformLocation("bloomDepthSampler", 2);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->colorBuffer);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, gFBO->depthTextureHandle);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, this->depthBuffer);
	glUniform2f(this->shader->getUniformLocation("screenSize"), static_cast<F32>(extent.x), static_cast<F32>(extent.y));
	GL_CheckErrors("activate bloom shader");

	// send verts
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, gFBO->quadVBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	GL_CheckErrors("send verts");
	// Draw the quad! Remember, it's 2 triangles!
	glDrawArrays(GL_TRIANGLES, 0, 6);
	GL_CheckErrors("draw quad");
	this->shader->deactivate();
	if (glIsEnabled(GL_TEXTURE_2D))
		glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}