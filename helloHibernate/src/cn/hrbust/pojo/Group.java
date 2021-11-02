package cn.hrbust.pojo;

import java.util.HashSet;
import java.util.Set;

public class Group {
  private int groupid;
  private String name;
  private Set users = new HashSet();

  public Set getUsers() {
    return users;
  }

  public void setUsers(Set users) {
    users = users;
  }

  public int getGroupid() {
    return groupid;
  }

  public void setGroupid(int groupid) {
    this.groupid = groupid;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }
}
