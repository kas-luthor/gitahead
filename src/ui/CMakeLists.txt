if(APPLE)
  set(IMPL_FILES MainWindow_mac.mm)
endif()

add_library(ui
  AdvancedSearchWidget.cpp
  Badge.cpp
  BlameEditor.cpp
  BlameMargin.cpp
  ColumnView.cpp
  CommitList.cpp
  CommitToolBar.cpp
  ContextMenuButton.cpp
  DetailView.cpp
  DiffView.cpp
  DiffWidget.cpp
  EditorWindow.cpp
  ExpandButton.cpp
  FileContextMenu.cpp
  FileList.cpp
  FindWidget.cpp
  Footer.cpp
  History.cpp
  HotkeyManager.cpp
  IndexCompleter.cpp
  Location.cpp
  MainWindow.cpp
  MenuBar.cpp
  PathspecWidget.cpp
  ProgressIndicator.cpp
  ReferenceList.cpp
  ReferenceView.cpp
  ReferenceWidget.cpp
  RepoView.cpp
  RemoteCallbacks.cpp
  SearchField.cpp
  SideBar.cpp
  TabBar.cpp
  TabWidget.cpp
  ToolBar.cpp
  TreeModel.cpp
  TreeWidget.cpp
  ${IMPL_FILES}
)

target_include_directories(ui PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(ui
  conf
  cred
  dialogs
  editor
  git
  host
  index
  loglib
  plugins
  tools
  update
  watcher
  Qt5::Concurrent
  Qt5::Network
  Qt5::Widgets
)

set_target_properties(ui PROPERTIES
  AUTOMOC ON
)
