using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro; // TextMesh Pro namespace
using UnityEngine.UI; // Image namespace

public class Chest : MonoBehaviour {
    /* -- Chest -- */
    public GameObject chest;
    GameObject player;
    bool isPlayerOnTrigger;
    bool isChestOpened;

    /* -- Loot -- */
    public GameObject loot;
    public int dropsAmmo;
    public int dropsHealth;

    /* -- UI -- */
    public GameObject UIButton;
    TextMeshProUGUI UItext;
    Image UIimage;
    Sprite keySprite;

    /* -- Animation -- */
    Animator animator;

    /* -- Audio -- */
    public AudioSource chestSource;
    public AudioSource coinSource;
    public AudioClip chestSound;
    public AudioClip coinsSound;

    void Start () {
        isPlayerOnTrigger = false;
        isChestOpened = false;
        animator = chest.GetComponent<Animator>();
        InitializeGameObjects();
    }

    void InitializeGameObjects() {
        /* -- Player -- */
        player = GameObject.Find("Player");

        /* -- UI Button -- */
        UItext = UIButton.GetComponentInChildren<TextMeshProUGUI>();
        UIimage = UIButton.GetComponentInChildren<Image>();
        keySprite = Resources.Load<Sprite>("E-Key");
    }

    void Update() {
        if (isPlayerOnTrigger && Input.GetKeyUp(KeyCode.E) && !isChestOpened) {
            isChestOpened = true;
            ShowUI(false);
            loot.SetActive(true);

            chestSource.clip = chestSound;
            chestSource.Play();
            coinSource.clip = coinsSound;
            coinSource.Play();

            animator.SetTrigger("move");
            Debug.Log(name + ": Player opened chest.");

            if (dropsAmmo > 0) {
                player.GetComponent<MovePlayer>().IncreaseAmmo(dropsAmmo);
            }
            if (dropsHealth > 0) {
                player.GetComponent<MovePlayer>().IncreaseHealth(dropsHealth);
            }
        }
    }

    void OnTriggerEnter(Collider other) {
        if (other.gameObject == player && !isChestOpened) {
            isPlayerOnTrigger = true;
            ShowUI(true);
            Debug.Log(name + ": Player entered Trigger.");
        }
    }

    void OnTriggerExit(Collider other) {
        if (other.gameObject == player) {
            isPlayerOnTrigger = false;
            ShowUI(false);
            Debug.Log(name + ": Player exited Trigger.");
        }
    }

    void ShowUI(bool show) {
        if (show && !isChestOpened) {
            UItext.text = "Open Chest";
            UIimage.sprite = keySprite;
            UIButton.SetActive(true);
        }
        else {
            UIButton.SetActive(false);
        }
    }
}