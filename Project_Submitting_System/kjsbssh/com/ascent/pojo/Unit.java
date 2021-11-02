//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.pojo;

import java.io.Serializable;
import java.util.HashSet;
import java.util.Set;

public class Unit implements Serializable {
  private Integer unitid;
  private User user;
  private String unitname;
  private String address;
  private String corporation;
  private String investment;
  private String type;
  private String tel;
  private String email;
  private String fax;
  private String zipcode;
  private String introduction;
  private String temp1;
  private String temp2;
  private String temp3;
  private String temp4;
  private Set projects = new HashSet(0);
  private Set categories = new HashSet(0);

  public Unit() {
  }

  public Unit(User user, String unitname, String address, String corporation, String investment, String type, String tel, String email, String fax, String zipcode, String introduction, String temp1, String temp2, String temp3, String temp4, Set projects, Set categories) {
    this.user = user;
    this.unitname = unitname;
    this.address = address;
    this.corporation = corporation;
    this.investment = investment;
    this.type = type;
    this.tel = tel;
    this.email = email;
    this.fax = fax;
    this.zipcode = zipcode;
    this.introduction = introduction;
    this.temp1 = temp1;
    this.temp2 = temp2;
    this.temp3 = temp3;
    this.temp4 = temp4;
    this.projects = projects;
    this.categories = categories;
  }

  public Integer getUnitid() {
    return this.unitid;
  }

  public void setUnitid(Integer unitid) {
    this.unitid = unitid;
  }

  public User getUser() {
    return this.user;
  }

  public void setUser(User user) {
    this.user = user;
  }

  public String getUnitname() {
    return this.unitname;
  }

  public void setUnitname(String unitname) {
    this.unitname = unitname;
  }

  public String getAddress() {
    return this.address;
  }

  public void setAddress(String address) {
    this.address = address;
  }

  public String getCorporation() {
    return this.corporation;
  }

  public void setCorporation(String corporation) {
    this.corporation = corporation;
  }

  public String getInvestment() {
    return this.investment;
  }

  public void setInvestment(String investment) {
    this.investment = investment;
  }

  public String getType() {
    return this.type;
  }

  public void setType(String type) {
    this.type = type;
  }

  public String getTel() {
    return this.tel;
  }

  public void setTel(String tel) {
    this.tel = tel;
  }

  public String getEmail() {
    return this.email;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public String getFax() {
    return this.fax;
  }

  public void setFax(String fax) {
    this.fax = fax;
  }

  public String getZipcode() {
    return this.zipcode;
  }

  public void setZipcode(String zipcode) {
    this.zipcode = zipcode;
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

  public Set getProjects() {
    return this.projects;
  }

  public void setProjects(Set projects) {
    this.projects = projects;
  }

  public Set getCategories() {
    return this.categories;
  }

  public void setCategories(Set categories) {
    this.categories = categories;
  }
}
