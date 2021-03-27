#!/bin/zsh
#
getargs() {
  while getopts "set" opt
  do
    case $opt in
      s) start="true";;
      e) end="true";;
      t) toggle="true";;
    esac
  done
}
start_dnd() {
  dunstctl set-paused true
}

end_dnd() {
  dunstctl set-paused false
  notify-send "Do Not Disturb" "Do Not Disturb mode ended. Notifications will be shown.";
}

toggle_dnd() {
  if [ $(dunstctl is-paused) = "false" ]; then
    start_dnd
  else
    end_dnd
  fi
}

main() {
  getargs "$@";
  [[ "$start" ]] && start_dnd;
  [[ "$end" ]] && end_dnd;
  [[ "$toggle" ]] && toggle_dnd;
  kill -52 $(pidof dwmblocks)
}
main "$@"