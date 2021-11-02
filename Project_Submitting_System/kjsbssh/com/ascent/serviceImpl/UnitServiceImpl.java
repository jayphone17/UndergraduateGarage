//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.serviceImpl;

import com.ascent.dao.UnitDao;
import com.ascent.pojo.Unit;
import com.ascent.service.UnitService;
import java.util.List;

public class UnitServiceImpl implements UnitService {
  UnitDao unitdao;

  public UnitServiceImpl() {
  }

  public UnitDao getUnitdao() {
    return this.unitdao;
  }

  public void setUnitdao(UnitDao unitdao) {
    this.unitdao = unitdao;
  }

  public void addUnit(Unit unit) {
    this.unitdao.addUnit(unit);
  }

  public void deleteUnit(Unit unit) {
    this.unitdao.deleteUnit(unit);
  }

  public List<Unit> findAllUnit(int pagno, int maxrows) {
    List<Unit> units = this.unitdao.findAllUnit(pagno, maxrows);
    return units;
  }

  public Unit findUnitById(Integer id) {
    Unit unit = this.unitdao.findUnitById(id);
    return unit;
  }

  public int getTotalCount() {
    int count = this.unitdao.getTotalCount();
    return count;
  }

  public void updateUnit(Unit unit) {
    this.unitdao.updateUnit(unit);
  }
}
