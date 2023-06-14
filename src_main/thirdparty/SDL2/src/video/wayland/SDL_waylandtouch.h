/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2018 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include "../../SDL_internal.h"

#ifdef SDL_VIDEO_DRIVER_WAYLAND_QT_TOUCH

#ifndef SDL_waylandtouch_h_
#define SDL_waylandtouch_h_

#include "SDL_waylandvideo.h"
#include <stdint.h>
#include <stddef.h>
#include "wayland-util.h"
#include "SDL_waylanddyn.h"


void Wayland_touch_create(SDL_VideoData *data, uint32_t id);
void Wayland_touch_destroy(SDL_VideoData *data);

struct qt_touch_extension;

/* Autogenerated QT headers */

/*
 Support for Wayland with QmlCompositor as Server
================================================

The Wayland video driver has support for some additional features when
using QtWayland's "qmlcompositor" as Wayland server. This is needed for touch
input when running SDL applications under a qmlcompositor Wayland server.

The files following headers have been
generated from the Wayland XML Protocol Definition in QtWayland as follows:

Clone QtWayland from Git:
    http://qt.gitorious.org/qt/qtwayland/

Generate headers and glue code:
    for extension in touch-extension surface-extension windowmanager; do
        wayland-scanner client-header < src/extensions/$extension.xml > wayland-qt-$extension.h
        wayland-scanner code < src/extensions/$extension.xml > wayland-qt-$extension.c
    done

*/

/* wayland-qt-surface-extension.h */

struct wl_client;
struct wl_resource;

struct qt_surface_extension;
struct qt_extended_surface;

extern const struct wl_interface qt_surface_extension_interface;
extern const struct wl_interface qt_extended_surface_interface;

#define QT_SURFACE_EXTENSION_GET_EXTENDED_SURFACE   0

static inline void
qt_surface_extension_set_user_data(struct qt_surface_extension *qt_surface_extension, void *user_data)
{
    wl_proxy_set_user_data((struct wl_proxy *) qt_surface_extension, user_data);
}

static inline void *
qt_surface_extension_get_user_data(struct qt_surface_extension *qt_surface_extension)
{
    return wl_proxy_get_user_data((struct wl_proxy *) qt_surface_extension);
}

static inline void
qt_surface_extension_destroy(struct qt_surface_extension *qt_surface_extension)
{
    WAYLAND_wl_proxy_destroy((struct wl_proxy *) qt_surface_extension);
}

static inline struct qt_extended_surface *
qt_surface_extension_get_extended_surface(struct qt_surface_extension *qt_surface_extension, struct wl_surface *surface)
{
    struct wl_proxy *id;

    id = wl_proxy_create((struct wl_proxy *) qt_surface_extension,
                 &qt_extended_surface_interface);
    if (!id)
        return NULL;

    WAYLAND_wl_proxy_marshal((struct wl_proxy *) qt_surface_extension,
             QT_SURFACE_EXTENSION_GET_EXTENDED_SURFACE, id, surface);

    return (struct qt_extended_surface *) id;
}

#ifndef QT_EXTENDED_SURFACE_ORIENTATION_ENUM
#define QT_EXTENDED_SURFACE_ORIENTATION_ENUM
enum qt_extended_surface_orientation {
    QT_EXTENDED_SURFACE_ORIENTATION_PRIMARYORIENTATION = 0,
    QT_EXTENDED_SURFACE_ORIENTATION_PORTRAITORIENTATION = 1,
    QT_EXTENDED_SURFACE_ORIENTATION_LANDSCAPEORIENTATION = 2,
    QT_EXTENDED_SURFACE_ORIENTATION_INVERTEDPORTRAITORIENTATION = 4,
    QT_EXTENDED_SURFACE_ORIENTATION_INVERTEDLANDSCAPEORIENTATION = 8,
};
#endif /* QT_EXTENDED_SURFACE_ORIENTATION_ENUM */

#ifndef QT_EXTENDED_SURFACE_WINDOWFLAG_ENUM
#define QT_EXTENDED_SURFACE_WINDOWFLAG_ENUM
enum qt_extended_surface_windowflag {
    QT_EXTENDED_SURFACE_WINDOWFLAG_OVERRIDESSYSTEMGESTURES = 1,
    QT_EXTENDED_SURFACE_WINDOWFLAG_STAYSONTOP = 2,
};
#endif /* QT_EXTENDED_SURFACE_WINDOWFLAG_ENUM */

struct qt_extended_surface_listener {
    /**
     * onscreen_visibility - (none)
     * @visible: (none)
     */
    void (*onscreen_visibility)(void *data,
                    struct qt_extended_surface *qt_extended_surface,
                    int32_t visible);
    /**
     * set_generic_property - (none)
     * @name: (none)
     * @value: (none)
     */
    void (*set_generic_property)(void *data,
                     struct qt_extended_surface *qt_extended_surface,
                     const char *name,
                     struct wl_array *value);
    /**
     * close - (none)
     */
    void (*close)(void *data,
              struct qt_extended_surface *qt_extended_surface);
};

static inline int
qt_extended_surface_add_listener(struct qt_extended_surface *qt_extended_surface,
                 const struct qt_extended_surface_listener *listener, void *data)
{
    return wl_proxy_add_listener((struct wl_proxy *) qt_extended_surface,
                     (void (**)(void)) listener, data);
}

#define QT_EXTENDED_SURFACE_UPDATE_GENERIC_PROPERTY 0
#define QT_EXTENDED_SURFACE_SET_CONTENT_ORIENTATION 1
#define QT_EXTENDED_SURFACE_SET_WINDOW_FLAGS    2

static inline void
qt_extended_surface_set_user_data(struct qt_extended_surface *qt_extended_surface, void *user_data)
{
    WAYLAND_wl_proxy_set_user_data((struct wl_proxy *) qt_extended_surface, user_data);
}

static inline void *
qt_extended_surface_get_user_data(struct qt_extended_surface *qt_extended_surface)
{
    return WAYLAND_wl_proxy_get_user_data((struct wl_proxy *) qt_extended_surface);
}

static inline void
qt_extended_surface_destroy(struct qt_extended_surface *qt_extended_surface)
{
    WAYLAND_wl_proxy_destroy((struct wl_proxy *) qt_extended_surface);
}

static inline void
qt_extended_surface_update_generic_property(struct qt_extended_surface *qt_extended_surface, const char *name, struct wl_array *value)
{
    WAYLAND_wl_proxy_marshal((struct wl_proxy *) qt_extended_surface,
             QT_EXTENDED_SURFACE_UPDATE_GENERIC_PROPERTY, name, value);
}

static inline void
qt_extended_surface_set_content_orientation(struct qt_extended_surface *qt_extended_surface, int32_t orientation)
{
    WAYLAND_wl_proxy_marshal((struct wl_proxy *) qt_extended_surface,
             QT_EXTENDED_SURFACE_SET_CONTENT_ORIENTATION, orientation);
}

static inline void
qt_extended_surface_set_window_flags(struct qt_extended_surface *qt_extended_surface, int32_t flags)
{
    WAYLAND_wl_proxy_marshal((struct wl_proxy *) qt_extended_surface,
             QT_EXTENDED_SURFACE_SET_WINDOW_FLAGS, flags);
}

/* wayland-qt-touch-extension.h */

extern const struct wl_interface qt_touch_extension_interface;

#ifndef QT_TOUCH_EXTENSION_FLAGS_ENUM
#define QT_TOUCH_EXTENSION_FLAGS_ENUM
enum qt_touch_extension_flags {
    QT_TOUCH_EXTENSION_FLAGS_MOUSE_FROM_TOUCH = 0x1,
};
#endif /* QT_TOUCH_EXTENSION_FLAGS_ENUM */

struct qt_touch_extension_listener {
    /**
     * touch - (none)
     * @time: (none)
     * @id: (none)
     * @state: (none)
     * @x: (none)
     * @y: (none)
     * @normalized_x: (none)
     * @normalized_y: (none)
     * @width: (none)
     * @height: (none)
     * @pressure: (none)
     * @velocity_x: (none)
     * @velocity_y: (none)
     * @flags: (none)
     * @rawdata: (none)
     */
    void (*touch)(void *data,
              struct qt_touch_extension *qt_touch_extension,
              uint32_t time,
              uint32_t id,
              uint32_t state,
              int32_t x,
              int32_t y,
              int32_t normalized_x,
              int32_t normalized_y,
              int32_t width,
              int32_t height,
              uint32_t pressure,
              int32_t velocity_x,
              int32_t velocity_y,
              uint32_t flags,
              struct wl_array *rawdata);
    /**
     * configure - (none)
     * @flags: (none)
     */
    void (*configure)(void *data,
              struct qt_touch_extension *qt_touch_extension,
              uint32_t flags);
};

static inline int
qt_touch_extension_add_listener(struct qt_touch_extension *qt_touch_extension,
                const struct qt_touch_extension_listener *listener, void *data)
{
    return wl_proxy_add_listener((struct wl_proxy *) qt_touch_extension,
                     (void (**)(void)) listener, data);
}

#define QT_TOUCH_EXTENSION_DUMMY    0

static inline void
qt_touch_extension_set_user_data(struct qt_touch_extension *qt_touch_extension, void *user_data)
{
    WAYLAND_wl_proxy_set_user_data((struct wl_proxy *) qt_touch_extension, user_data);
}

static inline void *
qt_touch_extension_get_user_data(struct qt_touch_extension *qt_touch_extension)
{
    return WAYLAND_wl_proxy_get_user_data((struct wl_proxy *) qt_touch_extension);
}

static inline void
qt_touch_extension_destroy(struct qt_touch_extension *qt_touch_extension)
{
    WAYLAND_wl_proxy_destroy((struct wl_proxy *) qt_touch_extension);
}

static inline void
qt_touch_extension_dummy(struct qt_touch_extension *qt_touch_extension)
{
    WAYLAND_wl_proxy_marshal((struct wl_proxy *) qt_touch_extension,
             QT_TOUCH_EXTENSION_DUMMY);
}


/* wayland-qt-windowmanager.h */

extern const struct wl_interface qt_windowmanager_interface;

struct qt_windowmanager_listener {
    /**
     * hints - (none)
     * @show_is_fullscreen: (none)
     */
    void (*hints)(void *data,
              struct qt_windowmanager *qt_windowmanager,
              int32_t show_is_fullscreen);
    /**
     * quit - (none)
     */
    void (*quit)(void *data,
             struct qt_windowmanager *qt_windowmanager);
};

static inline int
qt_windowmanager_add_listener(struct qt_windowmanager *qt_windowmanager,
                  const struct qt_windowmanager_listener *listener, void *data)
{
    return wl_proxy_add_listener((struct wl_proxy *) qt_windowmanager,
                     (void (**)(void)) listener, data);
}

#define QT_WINDOWMANAGER_OPEN_URL   0

static inline void
qt_windowmanager_set_user_data(struct qt_windowmanager *qt_windowmanager, void *user_data)
{
    WAYLAND_wl_proxy_set_user_data((struct wl_proxy *) qt_windowmanager, user_data);
}

static inline void *
qt_windowmanager_get_user_data(struct qt_windowmanager *qt_windowmanager)
{
    return WAYLAND_wl_proxy_get_user_data((struct wl_proxy *) qt_windowmanager);
}

static inline void
qt_windowmanager_destroy(struct qt_windowmanager *qt_windowmanager)
{
    WAYLAND_wl_proxy_destroy((struct wl_proxy *) qt_windowmanager);
}

static inline void
qt_windowmanager_open_url(struct qt_windowmanager *qt_windowmanager, uint32_t remaining, const char *url)
{
    WAYLAND_wl_proxy_marshal((struct wl_proxy *) qt_windowmanager,
             QT_WINDOWMANAGER_OPEN_URL, remaining, url);
}

#endif /* SDL_waylandtouch_h_ */

#endif /* SDL_VIDEO_DRIVER_WAYLAND_QT_TOUCH */
