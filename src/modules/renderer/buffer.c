#include "buffer.h"

void Buffer_Generate(Buffer self) {
  // self = malloc(sizeof(_Buffer));
  glGenBuffers(1, &(self->id));
}

void Buffer_SetTarget(Buffer self, unsigned int target) {
  self->target = target;
}

void Buffer_Data(Buffer self, size_t size, const void *data,
                 unsigned int usage) {
  int currentID = 0;
  // Add 0x2 to get the binding of buffer (Thank you OpenGL specification!)
  glGetIntegerv(self->target + 0x0002, &currentID);
  DEBUG_MSG("Get buffer binding at 0x%x, ID is %d", self->target + 0x0002,
            currentID);
  glBindBuffer(self->target, self->id);
  glBufferData(self->target, size, data, usage);
  glBindBuffer(currentID, self->target);
}

void Buffer_Free(Buffer self) {
  DEBUG_MSG("Free buffer at 0x%p, ID is %d", self, self->id);
  self->id = 0;
  self->target = 0;
  free(self);
}