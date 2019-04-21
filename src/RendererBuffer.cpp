#include "RendererBuffer.hpp"

using namespace std;

RendererBuffer::RendererBuffer(vector<Vertex> vertices) : vao(make_unique<VertexArrayObject>()) {
    glGenBuffers(1, &vbo);

    vao->bind();
    bind();

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(2 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
}

RendererBuffer::~RendererBuffer() {
    glDeleteBuffers(1, &vbo);
}

void RendererBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}
