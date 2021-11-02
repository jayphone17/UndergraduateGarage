package cn.hrbust.pojo;

import java.util.Date;
import java.util.HashSet;
import java.util.Set;

public class User {
  private int id;
  private String name;
  private String gender;
  private int age;
  Date birthday;
  Group group;
  private Card card;
  Set<Group> groups = new HashSet();

  public Set<Group> getGroups() {
    return groups;
  }

  public void setGroups(Set<Group> groups) {
    this.groups = groups;
  }

  public Card getCard() {
    return card;
  }

  public void setCard(Card card) {
    this.card = card;
  }

  public Group getGroup() {
    return group;
  }

  public void setGroup(Group group) {
    this.group = group;
  }

  public int getId() {
    return id;
  }

  public void setId(int id) {
    this.id = id;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getGender() {
    return gender;
  }

  public void setGender(String gender) {
    this.gender = gender;
  }

  public int getAge() {
    return age;
  }

  public void setAge(int age) {
    this.age = age;
  }

  public Date getBirthday() {
    return birthday;
  }

  public void setBirthday(Date birthday) {
    this.birthday = birthday;
  }

  public boolean equals(Object obj){
    if(this == obj){
      return true;
    }
    if(obj == null){
      return false;
    }
    if(!(obj instanceof User)){
      return false;
    }

    User other = (User)obj;
    if(id!=other.id)
      return false;
    if(age!=other.age)
      return false;
    if(!name.equals(other.name))
      return false;
    if(gender!=null && !gender.equals(other.gender))
      return false;
    if(!birthday.equals(other.birthday))
      return false;
    return true;
  }

  public int hashCode() {
    int result;
    result = getName().hashCode();
    result = 29 * result + getBirthday().hashCode();
    result = 29 * result + getAge();
    return result;
  }

  public String toString(){
    return "User [id=" + id + ",name=" + name + ",age=" + age + ",gender=" + gender + ",birthday=" + birthday;
  }

  public User(String username, int age){
    name = username;
    this.age=age;
  }

  public User() {
  }
}
