<template>
    <ContentBase>
        <div class="register-page">
            <div class="register-container">
                <h2>注册</h2>
                <form @submit.prevent="register">
                    <div class="form-group">
                        <input
                            type="text"
                            v-model="username"
                            placeholder="用户名"
                            required
                        />
                    </div>
                    <div class="form-group">
                        <input
                            type="password"
                            v-model="password"
                            placeholder="密码"
                            required
                        />
                    </div>
                    <div class="form-group">
                        <input
                            type="password"
                            v-model="password_confirm"
                            placeholder="确认密码"
                            required
                        />
                    </div>
                    <div class="error_message">{{ error_message }}</div>
                    <button type="submit">注册</button>
                </form>
                <div class="form-footer">
                    <span>已有账号？</span>
                    <router-link :to="{ name: 'login_index' }"
                        >登录</router-link
                    >
                </div>
            </div>
        </div>
    </ContentBase>
</template>

<script>
import { ref } from "vue";
import ContentBase from "../components/ContentBase.vue";
import router from "@/router/index";
import $ from "jquery";
import { useStore } from "vuex";
export default {
    name: "RegisterView",
    components: {
        ContentBase,
    },
    setup() {
        let username = ref("");
        let password = ref("");
        let password_confirm = ref("");
        let error_message = ref("");
        let store = useStore();

        const register = () => {
            $.ajax({
                url: "https://app165.acapp.acwing.com.cn/myspace/user/",
                type: "POST",
                data: {
                    username: username.value,
                    password: password.value,
                    password_confirm: password_confirm.value,
                },
                success: (resp) => {
                    if (resp.result === "success") {
                        store.dispatch("login", {
                            username: username.value,
                            password: password.value,
                            success: () => {
                                router.push({
                                    name: "userlist_index",
                                });
                            },
                            error: () => {
                                error_message.value = "系统异常";
                            },
                        });
                    } else {
                        error_message.value = resp.result;
                    }
                },
            });
        };

        return {
            username,
            password,
            password_confirm,
            error_message,
            register,
        };
    },
};
</script>

<style scoped>
.register-page {
    display: flex;
    justify-content: center;
    align-items: center;
    height: 50vh;
}

.register-container {
    width: 350px;
    padding: 40px;
    border-radius: 10px;
    background-color: #fff;
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
}

h2 {
    margin-bottom: 20px;
    text-align: center;
    font-size: 24px;
    color: #333;
}

.form-group {
    margin-bottom: 20px;
}

input[type="text"],
input[type="email"],
input[type="password"] {
    width: 100%;
    padding: 12px;
    border: none;
    border-radius: 5px;
    background-color: #f5f5f5;
    box-sizing: border-box;
    outline: none;
}

button {
    width: 100%;
    padding: 12px;
    background-color: #007bff;
    color: #fff;
    border: none;
    border-radius: 5px;
    cursor: pointer;
    outline: none;
    transition: background-color 0.3s ease;
}

button:hover {
    background-color: #0056b3;
}

.form-footer {
    text-align: center;
}

.form-footer span {
    margin-right: 5px;
    color: #666;
}

.form-footer a {
    color: #007bff;
    text-decoration: none;
}

.form-footer a:hover {
    text-decoration: underline;
    color: #0056b3;
}

.error_message {
    color: red;
}
</style>
