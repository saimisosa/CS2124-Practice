cmake_minimum_required(VERSION 3.15)
project(newBankAccount)

set(CMAKE_CXX_STANDARD 14)

add_executable(newBankAccount main.cpp BankManager.cpp BankManager.h BankAccount.cpp BankAccount.h Bank.cpp Bank.h)