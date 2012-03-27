#include <iostream>
#include "engine.hpp"
#include "game.hpp"

fff::engine::engine(){
    space = cpSpaceNew();
    cpSpaceSetGravity(space, (cpVect){0.f, 9.8f});
    cpSpaceAddBody(space, kitty.body);
    shapefloor = cpSegmentShapeNew(cpSpaceGetStaticBody(space), (cpVect){0.f, 4.f}, (cpVect){640.f, 4.f}, 4.f);
    cpSpaceAddShape(space, shapefloor);
    floor.SetPosition(0, 0);
    camera.SetCenter(320, 240);
    camera.SetSize(640, 480);
    kitty.setPosition(320, -250);
}

fff::engine::~engine(){
    cpShapeFree(shapefloor);
    cpSpaceFree(space);
}

void fff::engine::Reset(){
}

void fff::engine::loadResources(){
    floor.SetTexture(*game.textures["floor"]);
    kitty.sprite.SetTexture(*game.textures["kitty"]);
    kitty.Update();
}

void fff::engine::Event(sf::Event &event){
}

void fff::engine::Run(sf::RenderTarget &rendertarget){
    sf::Uint32 currenttime = game.realwindow.GetFrameTime();
    cpSpaceStep(space, currenttime/1000.f);
    time += currenttime;
    if (time >= 1000){
        // time <= 1 sec
        //generate events
        time = 0; 
    }
    kitty.Update();
    sf::Vector2f camerapos = camera.GetCenter();
    //std::cout << "Height: " << kitty.getHeight() << std::endl;
    //camerapos.y = kitty.getHeight();
    //camera.SetCenter(camerapos);
    if (kitty.getHeight() <= -240+32){
        camerapos.y = kitty.getHeight();
        camera.SetCenter(camerapos);
    }
    rendertarget.SetView(camera);
    rendertarget.Draw(kitty.sprite);
    rendertarget.Draw(floor);
}