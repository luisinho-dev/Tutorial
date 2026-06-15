#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <cstdlib>

using namespace geode::prelude;

float tempoDecorrido = 0.0f;
// Começa com 8 segundos para dar tempo de começar a fase tranquilo
float proximaInversao = 8.0f; 

class $modify(PlayerObject) {
    void update(float dt) {
        PlayerObject::update(dt);

        if (auto playLayer = PlayLayer::get()) {
            // Garante que só afeta o player principal e que a fase está rodando normal
            if (this == playLayer->m_player1 && !playLayer->m_isDead) {
                
                tempoDecorrido += dt;

                if (tempoDecorrido >= proximaInversao) {
                    // Reseta o cronômetro NA HORA para não repetir no próximo frame
                    tempoDecorrido = 0.0f; 

                    // Inverte a gravidade do boneco de forma limpa
                    this->flipGravity(!m_isUpsideDown, true);

                    // Cria um aviso grande no meio da tela
                    Notification::create("Gravity changed!", NotificationIcon::Warning)->show();

                    // Gera um tempo justo: entre 6 e 15 segundos para a próxima inversão
                    proximaInversao = 6.0f + static_cast<float>(rand() % 10);
                }
            }
        }
    }
};
