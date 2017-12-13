// Copyright 2017 Dirk Hutter <cmail@dirk-hutter.de>
#pragma once

#include "etcd/Client.hpp"

namespace etcd {

class Watcher {

public:
  Watcher(std::string const& address,
          std::string const& key,
          std::function<void(etcd::Response)> callback,
          bool recursive = false);

  Watcher(std::string const& address,
          std::string const& key,
          int from_index,
          std::function<void(etcd::Response)> callback,
          bool recursive = false);

  ~Watcher();

  void cancel();

  void renew_watch();

private:
  void watch();

  etcd::Client _etcd;
  std::string _key;
  std::function<void(etcd::Response)> _callback;
  bool _recursive;
  int _index;
};

} // namespace
