using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
public class BalaEnemy : BalaBase {
    GameObject prefab;
    public void init() {
        rotationSpeed = -70.0f;
        damage = 10.0f;
        initBala();
        prefab = Resources.Load<GameObject>("SmallExplosion");
        Center = transform.parent.position;
    }

    void FixedUpdate() {
        Move();
    }

    protected void OnTriggerEnter(Collider other) {
        MeshRenderer mesh = GetComponent<MeshRenderer>();
        mesh.enabled = false;

        if (other.gameObject.tag == "Player") {
            MovePlayer player = other.gameObject.GetComponent<MovePlayer>();
            player.TakeDamage(GetDamage());
        }

        GameObject explosion = Instantiate(prefab, transform.position, Quaternion.identity);
        Destroy(explosion, 1.0f);
        Destroy(gameObject);
    }
}
