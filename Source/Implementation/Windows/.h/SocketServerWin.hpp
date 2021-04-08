#pragma once
#include <mutex>
#include "IRunnable.hpp"
#include "Settings.hpp"
#include "Control.hpp"
#include "Channel.hpp"
#include "SocketServer.hpp"

namespace cm {
    class SocketServerWin final: public SocketServer {
        public:
            SocketServerWin(const SocketServerSettings& settings) { _settings = settings; init(); }
            virtual ~SocketServerWin();
            void init();
            void run() override;

            bool sendMessageImpl(const std::string& msg) override;
            bool sendDataImpl(const char* data, size_t lenght) override;
        private:
            std::mutex guard;
            SocketServerSettings _settings;
    };
}