//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.serviceImpl;

import com.ascent.dao.ExpertDao;
import com.ascent.pojo.Expert;
import com.ascent.service.ExpertService;
import java.util.List;

public class ExpertServiceImpl implements ExpertService {
  ExpertDao expertdao;

  public ExpertServiceImpl() {
  }

  public void addExpert(Expert expert) {
    this.expertdao.addExpert(expert);
  }

  public void deleteExpert(Expert expert) {
    this.expertdao.deleteExpert(expert);
  }

  public List<Expert> findAllExpert(int pagno, int maxrows) {
    List<Expert> experts = this.expertdao.findAllExpert(pagno, maxrows);
    return experts;
  }

  public Expert findExpertById(Integer id) {
    Expert expert = this.expertdao.findExpertById(id);
    return expert;
  }

  public int getTotalCount() {
    int count = this.expertdao.getTotalCount();
    return count;
  }

  public void updateExpert(Expert expert) {
    this.expertdao.updateExpert(expert);
  }

  public ExpertDao getExpertdao() {
    return this.expertdao;
  }

  public void setExpertdao(ExpertDao expertdao) {
    this.expertdao = expertdao;
  }
}
