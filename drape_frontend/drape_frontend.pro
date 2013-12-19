TARGET = drape_frontend
TEMPLATE = lib
CONFIG += staticlib

DEPENDENCIES = base
ROOT_DIR = ..
include($$ROOT_DIR/common.pri)

SOURCES += \
    backend_renderer.cpp \
    engine_context.cpp \
    memory_feature_index.cpp \
    message_queue.cpp \
    message.cpp \
    threads_commutator.cpp \
    message_acceptor.cpp \
    impl/backend_renderer_impl.cpp \
    read_mwm_task.cpp \
    batchers_pool.cpp

HEADERS += \
    backend_renderer.hpp \
    render_thread.hpp \
    engine_context.hpp \
    memory_feature_index.hpp \
    tile_info.hpp \
    message_queue.hpp \
    message.hpp \
    threads_commutator.hpp \
    message_acceptor.hpp \
    impl/backend_renderer_impl.hpp \
    read_mwm_task.hpp \
    message_subclasses.hpp \
    map_shape.hpp \
    batchers_pool.hpp
