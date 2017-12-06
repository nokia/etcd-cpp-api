// Copyright 2017 Dirk Hutter <cmail@dirk-hutter.de>

#include "etcd/Watcher.hpp"

etcd::Watcher::Watcher(std::string const& address,
                       std::string const& key,
                       std::function<void(etcd::Response)> callback,
                       bool recursive)
    : _etcd(address), _key(key), _callback(callback), _recursive(recursive) {
  // start initial watch from etcd index to allow non existing keys
  _index = _etcd.get(key).get().index();
  watch();
}

etcd::Watcher::~Watcher() { cancel(); }

void etcd::Watcher::cancel() { _etcd.cancel(); }

void etcd::Watcher::renew_watch() { watch(); }

void etcd::Watcher::watch() {
  _etcd.watch(_key, _index + 1, _recursive)
      .then([this](pplx::task<etcd::Response> resp_task) {
        try {
          etcd::Response resp = resp_task.get();
          _index = resp.value().modified_index();
          _callback(resp);
        } catch (web::http::http_exception) {
          // renew watch in case of prematurely closed connection
          watch();
        }
      });
}
