// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __ICommand_h__
#define __ICommand_h__
////////////////////////////////////////////////////////////////////////////////
/// Interface for all commands.
class ICommand
{
public:
  /// Executes command.
  virtual void Execute() = 0;
};
////////////////////////////////////////////////////////////////////////////////
#endif
