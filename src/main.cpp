#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <cstdlib>

using namespace geode::prelude;

float tempoDecorrido = 0.0f;
float proximaInversao = 8.0f;

class $modify(PlayerObject) {
    void update(float dt) {
        PlayerObject::update(dt);

        if (this == m_gameLayer->m_player1) {
            tempoDecorrido += dt;

            if (tempoDecorrido >= proximaInversao) {
                this->flipGravity(!m_isUpsideDown, true);

                Notification::create("GRAVIDADE ALTERADA!", NotificationIcon::Warning)->show();

                tempoDecorrido = 0.0f;
                proximaInversao = 5.0f + static_cast<float>(rand() % 11);
            }
        }
    }
};

