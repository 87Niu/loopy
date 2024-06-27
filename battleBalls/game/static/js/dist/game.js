class AcGameMenu {
    constructor(root) {
        this.root = root;
        this.$menu = $(`
            <div class="ac-game-menu">
                <div class="ac-game-menu-field">
                    <div class="ac-game-menu-field-item ac-game-menu-field-item-single">单人模式</div><br/>
                    <div class="ac-game-menu-field-item ac-game-menu-field-item-multi">多人模式</div><br/>
                    <div class="ac-game-menu-field-item ac-game-menu-field-item-settings">设置</div>
                </div>
            </div>
        `);

        this.root.$ac_game.append(this.$menu);
        this.$single_mode = this.$menu.find('.ac-game-menu-field-item-single');
        this.$multi_mode = this.$menu.find('.ac-game-menu-field-item-multi');
        this.$settings_mode = this.$menu.find('.ac-game-menu-field-item-settings');

        this.start();
    }   

    start() {
        this.add_listening_event();
    }

    add_listening_event() {
        let outer = this;
        this.$single_mode.click(function() {
            outer.hide();
            outer.root.playground.show();
        });
        this.$multi_mode.click(function() {
            console.log("click multi");
        });
        this.$settings_mode.click(function() {
            console.log("click settings");
        })
    }

    show() {
        this.$menu.show();
    }

    hide() {
        this.$menu.hide();
    }
}
class AcGamePlayground {
    constructor(root) {
        this.root = root;

        this.$playground = $(`<div>游戏界面</div>`);

        this.hide();
        this.root.$ac_game.append(this.$playground);
    }

    start() {

    }

    show() {
        this.$playground.show();
    }

    hide() {
        this.$playground.hide();
    }
}export class AcGame {
    constructor(id) {
        this.$ac_game = $('#' + id);
        this.ac_game_menu = new AcGameMenu(this);

        this.playground = new AcGamePlayground(this);

        this.start();
    }

    start() {

    }
}