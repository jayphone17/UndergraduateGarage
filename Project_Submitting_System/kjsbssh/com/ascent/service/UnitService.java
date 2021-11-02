//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.service;

import com.ascent.pojo.Unit;
import java.util.List;

public interface UnitService {
  void addUnit(Unit var1);

  void deleteUnit(Unit var1);

  void updateUnit(Unit var1);

  Unit findUnitById(Integer var1);

  List<Unit> findAllUnit(int var1, int var2);

  int getTotalCount();
}
