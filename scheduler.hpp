#pragma once

#include <boost/asio.hpp>
#include <boost/thread.hpp>

enum async_type_t {
  UseAsync
};

class Scheduler {
public:
  Scheduler() :
    work_(new boost::asio::io_service::work(io_service_)),
    thread_(boost::bind(&boost::asio::io_service::run, &io_service_)) {
  }

  ~Scheduler() {
    io_service_.stop();
    thread_.join();
  }

//protected:
  boost::asio::io_service io_service_;
  boost::asio::io_service::work* work_;
  boost::thread thread_;
};
