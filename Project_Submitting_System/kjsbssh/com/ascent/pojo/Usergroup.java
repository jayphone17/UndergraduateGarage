//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.pojo;

import java.io.Serializable;
import java.util.HashSet;
import java.util.Set;

public class Usergroup implements Serializable {
  private Integer gid;
  private String gname;
  private Set users = new HashSet(0);

  public Usergroup() {
  }

  public Usergroup(String gname) {
    this.gname = gname;
  }

  public Usergroup(String gname, Set users) {
    this.gname = gname;
    this.users = users;
  }

  public Integer getGid() {
    return this.gid;
  }

  public void setGid(Integer gid) {
    this.gid = gid;
  }

  public String getGname() {
    return this.gname;
  }

  public void setGname(String gname) {
    this.gname = gname;
  }

  public Set getUsers() {
    return this.users;
  }

  public void setUsers(Set users) {
    this.users = users;
  }
}
