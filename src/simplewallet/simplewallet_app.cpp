// Copyright (c) 2017-2018 The Purk Project Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "simplewallet.h"

int main(int argc, char* argv[])
{
  tools::set_confirmation_dialog(false);  
  return currency::run_wallet_rpc(argc, argv);
  //CATCH_ENTRY_L0("main", 1);
}
