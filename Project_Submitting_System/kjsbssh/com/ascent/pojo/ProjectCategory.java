//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.pojo;

import java.io.Serializable;
import java.util.Date;
import java.util.HashSet;
import java.util.Set;

public class ProjectCategory implements Serializable {
  private Integer categoryid;
  private Expert expert;
  private String categoryname;
  private Date repStartTime;
  private Date repStopTime;
  private Date expStartTime;
  private Date expStopTime;
  private Set projects = new HashSet(0);
  private Set units = new HashSet(0);

  public ProjectCategory() {
  }

  public ProjectCategory(String categoryname) {
    this.categoryname = categoryname;
  }

  public ProjectCategory(Expert expert, String categoryname, Date repStartTime, Date repStopTime, Date expStartTime, Date expStopTime, Set projects, Set units) {
    this.expert = expert;
    this.categoryname = categoryname;
    this.repStartTime = repStartTime;
    this.repStopTime = repStopTime;
    this.expStartTime = expStartTime;
    this.expStopTime = expStopTime;
    this.projects = projects;
    this.units = units;
  }

  public Integer getCategoryid() {
    return this.categoryid;
  }

  public void setCategoryid(Integer categoryid) {
    this.categoryid = categoryid;
  }

  public Expert getExpert() {
    return this.expert;
  }

  public void setExpert(Expert expert) {
    this.expert = expert;
  }

  public String getCategoryname() {
    return this.categoryname;
  }

  public void setCategoryname(String categoryname) {
    this.categoryname = categoryname;
  }

  public Date getRepStartTime() {
    return this.repStartTime;
  }

  public void setRepStartTime(Date repStartTime) {
    this.repStartTime = repStartTime;
  }

  public Date getRepStopTime() {
    return this.repStopTime;
  }

  public void setRepStopTime(Date repStopTime) {
    this.repStopTime = repStopTime;
  }

  public Date getExpStartTime() {
    return this.expStartTime;
  }

  public void setExpStartTime(Date expStartTime) {
    this.expStartTime = expStartTime;
  }

  public Date getExpStopTime() {
    return this.expStopTime;
  }

  public void setExpStopTime(Date expStopTime) {
    this.expStopTime = expStopTime;
  }

  public Set getProjects() {
    return this.projects;
  }

  public void setProjects(Set projects) {
    this.projects = projects;
  }

  public Set getUnits() {
    return this.units;
  }

  public void setUnits(Set units) {
    this.units = units;
  }
}
