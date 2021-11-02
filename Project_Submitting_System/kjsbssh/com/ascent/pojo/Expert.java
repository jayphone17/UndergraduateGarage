//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.pojo;

import java.io.Serializable;
import java.util.HashSet;
import java.util.Set;

public class Expert implements Serializable {
  private Integer expertid;
  private User user;
  private String name;
  private String nation;
  private String sex;
  private String unitname;
  private String title;
  private String tel;
  private String introduction;
  private String temp1;
  private String temp2;
  private String temp3;
  private String temp4;
  private Set<ProjectCategory> projectCategories = new HashSet();

  public Expert() {
  }

  public Expert(User user, String name, String nation, String sex, String unitname, String title, String tel, String introduction, String temp1, String temp2, String temp3, String temp4, Set<ProjectCategory> projectCategories) {
    this.user = user;
    this.name = name;
    this.nation = nation;
    this.sex = sex;
    this.unitname = unitname;
    this.title = title;
    this.tel = tel;
    this.introduction = introduction;
    this.temp1 = temp1;
    this.temp2 = temp2;
    this.temp3 = temp3;
    this.temp4 = temp4;
    this.projectCategories = projectCategories;
  }

  public Integer getExpertid() {
    return this.expertid;
  }

  public void setExpertid(Integer expertid) {
    this.expertid = expertid;
  }

  public User getUser() {
    return this.user;
  }

  public void setUser(User user) {
    this.user = user;
  }

  public String getName() {
    return this.name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getNation() {
    return this.nation;
  }

  public void setNation(String nation) {
    this.nation = nation;
  }

  public String getSex() {
    return this.sex;
  }

  public void setSex(String sex) {
    this.sex = sex;
  }

  public String getUnitname() {
    return this.unitname;
  }

  public void setUnitname(String unitname) {
    this.unitname = unitname;
  }

  public String getTitle() {
    return this.title;
  }

  public void setTitle(String title) {
    this.title = title;
  }

  public String getTel() {
    return this.tel;
  }

  public void setTel(String tel) {
    this.tel = tel;
  }

  public String getIntroduction() {
    return this.introduction;
  }

  public void setIntroduction(String introduction) {
    this.introduction = introduction;
  }

  public String getTemp1() {
    return this.temp1;
  }

  public void setTemp1(String temp1) {
    this.temp1 = temp1;
  }

  public String getTemp2() {
    return this.temp2;
  }

  public void setTemp2(String temp2) {
    this.temp2 = temp2;
  }

  public String getTemp3() {
    return this.temp3;
  }

  public void setTemp3(String temp3) {
    this.temp3 = temp3;
  }

  public String getTemp4() {
    return this.temp4;
  }

  public void setTemp4(String temp4) {
    this.temp4 = temp4;
  }

  public Set<ProjectCategory> getProjectCategories() {
    return this.projectCategories;
  }

  public void setProjectCategories(Set<ProjectCategory> projectCategories) {
    this.projectCategories = projectCategories;
  }
}
