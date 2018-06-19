#include "Program.h"

#include "ProgramState_Play.h"
#include "ProgramState_MainMenu.h"

Program::Program() {
    m_window = std::unique_ptr<sf::RenderWindow>
               (new sf::RenderWindow(sf::VideoMode(800,600),
                                     "zemianadrezh"));
    m_window->setFramerateLimit(60);

    //m_states.push(std::unique_ptr<ProgramState_Play>(new ProgramState_Play(*this)));
    m_states.push(std::unique_ptr<ProgramState_MainMenu>(new ProgramState_MainMenu(*this)));

    gameLoop();
}

Program::~Program() {

}

void Program::init() {

}

void Program::gameLoop() {
    while(m_window->isOpen()) {
        m_window->clear(sf::Color(61,122,77));

        //Monitor window closing
        /////////////////////////////////////////////////////
        sf::Event event;
        while(m_window->pollEvent(event)) {

            if(event.type == sf::Event::Closed) {
                m_window->close();
            }

            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Escape) {
                    m_window->close();
                }
            }

        }
        /////////////////////////////////////////////////////

        m_states.top()->getInput();
        m_states.top()->update();
        m_states.top()->draw();

        m_window->display();
    }
}






