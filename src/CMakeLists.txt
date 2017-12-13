add_library(etcd-cpp-api SHARED Client.cpp Response.cpp Value.cpp json_constants.cpp Watcher.cpp)
set_property(TARGET etcd-cpp-api PROPERTY CXX_STANDARD 11)

target_include_directories(etcd-cpp-api PUBLIC ..)
target_include_directories(etcd-cpp-api SYSTEM PUBLIC ${CPPREST_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

target_link_libraries(etcd-cpp-api ${CPPREST_LIBRARY} ${Boost_LIBRARIES} ssl crypto)

install (TARGETS etcd-cpp-api DESTINATION lib)
install (FILES ../etcd/Client.hpp
               ../etcd/Response.hpp
               ../etcd/Value.hpp
               ../etcd/Watcher.hpp
               DESTINATION include/etcd)
