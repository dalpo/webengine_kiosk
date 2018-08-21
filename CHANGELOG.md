# Changelog

## v0.2.0

This version will refuse to run as root. If it didn't catch it,
then Chromium would have. Since there are many reasons not to run a web browser
as root, webengine_kiosk takes the easy route of not allowing it. If started as
root, it will attempt to switch to the kiosk:kiosk user. Use the `uid`, `gid`,
and `data_dir` options to manually select user, group and a good writable
location for temp files.

* Improvements
  * Many options work now and have better documentation
  * Added keyboard shortcuts for reloading (F5), going
    back and forward (Ctrl-[ and Ctrl-]), and more. Options
    that were one time in menus are now shortcuts if debug
    is enabled.

## v0.1.0

Initial release

