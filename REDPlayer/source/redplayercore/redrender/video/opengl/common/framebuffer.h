#pragma once

#include <memory>
#include <vector>

#include "../../video_inc_internal.h"

#if (REDRENDER_PLATFORM == REDRENDER_PLATFORM_ANDROID) ||                      \
    (REDRENDER_PLATFORM == REDRENDER_PLATFORM_HARMONY)
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#elif REDRENDER_PLATFORM == REDRENDER_PLATFORM_IOS
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#endif

NS_REDRENDER_BEGIN

typedef struct TextureAttributes {
  GLenum minFilter;
  GLenum magFilter;
  GLenum wrapS;
  GLenum wrapT;
  GLenum internalFormat;
  GLenum format;
  GLenum type;
} TextureAttributes;

// opengl framebuffer class
class Framebuffer {
public:
  Framebuffer(const int &sessionID = 0);
  Framebuffer(
      int width, int height, bool onlyGenerateTexture = false,
      const TextureAttributes textureAttributes = defaultTextureAttribures,
      const int &sessionID = 0);
  static std::shared_ptr<Framebuffer> create(const int &sessionID = 0);
  static std::shared_ptr<Framebuffer>
  create(int width, int height, bool onlyGenerateTexture = false,
         const TextureAttributes textureAttributes = defaultTextureAttribures,
         const int &sessionID = 0);
  virtual ~Framebuffer();

  virtual void release();
  GLuint getTexture() const { return _texture; }
  GLuint getFramebuffer() const { return _framebuffer; }
  int getWidth() const { return _width; }
  int getHeight() const { return _height; }
  const TextureAttributes &getTextureAttributes() const {
    return _textureAttributes;
  }
  bool hasFramebuffer() { return _hasFramebuffer; }

  void setViewPort();
  void activeFramebuffer();
  void inActiveFramebuffer();
#if REDRENDER_PLATFORM == REDRENDER_PLATFORM_IOS
  void setTexture(GLuint texture);
  void setWidth(int width);
  void setHeight(int height);
#endif

public:
  static TextureAttributes defaultTextureAttribures;

private:
  int _width{0}, _height{0};
  TextureAttributes _textureAttributes;
  bool _hasFramebuffer{false};
  GLuint _texture;
  GLuint _framebuffer;
  const int _sessionID{0};
  bool _isTextureCache{false};

  void _generateTexture();
  void _generateFramebuffer();
};

NS_REDRENDER_END
