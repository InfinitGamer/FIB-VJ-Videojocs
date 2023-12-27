using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BalaPlayer : BalaBase {
    // Start is called before the first frame update

    public void init() {
        rotationSpeed = -10.0f;
        damage = 10.0f;
        base.initBala();
        Debug.Log(rotacionInicial);
    }

    // Update is called once per frame
    void FixedUpdate() {

        Move();
    }
    protected void OnTriggerEnter(Collider other) {
        Debug.Log(other.gameObject.name + " ha entrado en el colider de " + gameObject.name);
        

        if (other.gameObject.tag == "Enemy") {
            EnemyBase enemy = other.gameObject.GetComponent<EnemyBase>();
            enemy.takeDamage(GetDamage());
        }

        Destroy(gameObject);
    }
    
}