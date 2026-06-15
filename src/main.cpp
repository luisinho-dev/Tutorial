#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <cstdlib>

using namespace geode::prelude;

float tempoDecorrido = 0.0f;
float proximaInversao = 8.0f;

class $modify(PlayerObject) {
    void update(float dt) {
        PlayerObject::update(dt);

        // Versão compatível com Geode 2.2081
        if (auto playLayer = PlayLayer::get()) {
            if (this == playLayer->m_player1) {
                tempoDecorrido += dt;

                if (tempoDecorrido >= proximaInversao) {
                    // Inverte a gravidade usando a variável correta de checagem
                    this->flipGravity(!m_isUpsideDown, true);

                    Notification::create("GRAVIDADE ALTERADA!", NotificationIcon::Warning)->show();

                    tempoDecorrido = 0.0f;
                    proximaInversao = 5.0f + static_cast<float>(rand() % 11);
                }
            }
        }
    }
};
