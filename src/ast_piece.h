#ifndef AST_PIECE
#define AST_PIECE

#include "destroyable.h"
#include <raylib.h>

extern Texture2D t_astPiece[4];

class AstPiece : public Destroyable {

public:

    AstPiece(int=0, int=0, int=0, Vec2=Vec2(0,0));
    ~AstPiece();

    void step() override;
    void draw() const override;
    

private:
    int frame;
};

#endif