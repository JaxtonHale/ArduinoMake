#ifndef FRIDGE_GENIE_H
#define FRIDGE_GENIE_H

class FridgeGenie
{
public:
  FridgeGenie();
  void run();
  static FridgeGenie* instance();

  FridgeGenie(FridgeGenie const&) = delete;
  FridgeGenie& operator=(FridgeGenie const&) = delete;
private:
   static FridgeGenie* m_p_instance;
};

#endif
