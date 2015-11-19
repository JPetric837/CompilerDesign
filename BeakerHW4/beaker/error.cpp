// Copyright (c) 2015 Andrew Sutton
// All rights reserved

#include "error.hpp"

#include <iostream>


// TODO: Add colors!
void
diagnose(Translation_error& err)
{
  std::cerr << bright_red("error") << ':' 
            << bright_white(err.location()) << ": " << err.what() << '\n';
}
